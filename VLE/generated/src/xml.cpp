//#define __DEBUG_XML__
#include <assert.h>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

#include "xml.hpp"
#include "tests.hpp"

using namespace std;
using boost::lexical_cast;
using boost::format;

namespace generated {
const XmlNode	empty;


/**
 * returns the list of all child names
 * @param children list
 */
void    XmlNode::getChildrenNames(t_names&      children) const
{
  for (t_nodeMap::const_iterator        it = nodes.begin(); nodes.end() != it;
       it++)
    children.push_back(it->first);
}

/**
 * returns the list of all nodes names
 * @param children list
 */
void    XmlNode::getNodes(t_names&      thenodes) const
{
  for (t_names::const_iterator  it = nodenames.begin();
       nodenames.end() != it; it++)
    thenodes.push_back(*it);
}

/**
 * returns the list of all attributes names
 * @param children list
 */
void    XmlNode::getAttributes(t_names&      attr) const
{
  for (t_names::const_iterator  it = attributes.begin();
       attributes.end() != it; it++)
    attr.push_back(*it);
}

/**
 * Constructor
 * @param theName node name
 * @param theParent father node
 */
XmlNode::XmlNode(string         theName,
                 XmlNode*       theParent)
{
  name = theName;
  parent = theParent;
}


/**
 * Constructor
 * @param buff the xml string
 */
XmlNode::XmlNode(string         buff)
{
  name = "root";
  parent = NULL;
  XmlParser(this, buff);
}


/**
 * Copy constructor
 * @param node is the node to copy
 */
XmlNode::XmlNode(const XmlNode&      node)
{
  name = node.name;
  parent = NULL;
  value = node.value;
  nodenames = node.nodenames;
  attributes = node.attributes;

  for (t_nodeMap::const_iterator        it = node.nodes.begin();
       node.nodes.end() != it; it++)
  {
    XmlNode*    new_node = new XmlNode(*(it->second));

    new_node->parent = this;
    nodes[it->first] = new_node;
  }
}

/**
 * Copy Constructor
 */
XmlNode::XmlNode(void)
{
  name = "root";
  parent = NULL;
}

/**
 * Destructor
 */
XmlNode::~XmlNode(void)
{
  if (nodes.size() > 0)
  {
    for (t_nodeMap::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
      XmlNode*  n = it->second;

      delete (n);
      n = NULL;
    }
    nodes.clear();
    nodenames.clear();
    attributes.clear();
  }
}


/**
 * set the value of this node
 * @param theValue the value
 */
void    XmlNode::setValue(string        theValue)
{
  value = theValue;
#ifdef __DEBUG_XML__
    cout << "\t" << "setValue> node '" << name << "' : '" << value << "'" << endl;
#endif // __DEBUG_XML__
}

/**
 * Add a child to this node
 * @param theName name of this child
 * @return new child node
 */
XmlNode*        XmlNode::add(string     theName)
{
  int           pos = theName.find('.');

  if (pos > 0)
  {
    string              sub = theName.substr(0, pos);
    string              sup = theName.substr(pos + 1);
    XmlNode*            subNode = nfind(sub);
    XmlNode*            res = NULL;

    if (subNode)
      res =  subNode->add(sup);
    else
    {
      subNode = add(sub);
      res = subNode->add(sup);
    }

    return (res);
  }

  unsigned int  count = 0;
  string        newName(theName);
  XmlNode*      nc;

  nc = nfind(newName);
  while (NULL != nc)
  {
    count++;
    newName = str(format("%s#%d") % theName % count);
    nc = nfind(newName);
  }

  XmlNode*      n = new XmlNode(newName, this);

  nodes[newName]=n;
  nodenames.push_back(newName);
  return (n);
}

/**
 * Add a child to this node
 * @param node is the node to add (a root node)
 * @return new child node
 */
XmlNode*        XmlNode::add(XmlNode&   node)
{
  unsigned int  count = 0;
  XmlNode*      nc = NULL;
  string        newName = node.name;

  node.parent = this;
  nc = nfind(newName);
  while (NULL != nc)
  {
    count++;
    newName = str(format("%s#%d") % node.name % count);
    nc = nfind(newName);
  }

  node.name = newName;
  nodes[node.name]=&node;
  nodenames.push_back(node.name);
  return (&node);
}

/**
 * Add a child to this node copying it
 * @param node is the node to add (a root node)
 * @return new child node
 */
XmlNode*        XmlNode::add(const XmlNode&   node)
{
  setValue(node.get());

  // Add attributes
  for (t_names::const_iterator  it = node.attributes.begin();
       node.attributes.end() != it; it++)
  {
    string                      nm = *it;
    t_nodeMap::const_iterator   attr = node.nodes.find(nm);

    __REQUIRE(node.nodes.end() != attr);
    __REQUIRE(NULL != attr->second);

    add(nm, attr->second->get());
  }

  // Add child nodes
  for (t_names::const_iterator  it = node.nodenames.begin();
       node.nodenames.end() != it; it++)
  {
    string                      nm = *it;
    t_nodeMap::const_iterator   subNode = node.nodes.find(nm);

    __REQUIRE(node.nodes.end() != subNode);
    __REQUIRE(NULL != subNode->second);

    add(nm)->merge(*(subNode->second));
  }

  return (this);
}


/**
 * Merge a node into this one
 * @param node is the node to add
 * @return new child node
 */
XmlNode*        XmlNode::merge(const XmlNode&   node)
{
  setValue(node.get());

  // Add attributes
  for (t_names::const_iterator  it = node.attributes.begin();
       node.attributes.end() != it; it++)
  {
    string                      nm = *it;
    t_nodeMap::const_iterator   attr = node.nodes.find(nm);

    __REQUIRE(node.nodes.end() != attr);
    __REQUIRE(NULL != attr->second);
    t_nodeMap::const_iterator   thisAttr = nodes.find(nm);

    if (nodes.end() == thisAttr)
      add(nm, attr->second->get());
    else
      thisAttr->second->setValue(attr->second->get());
  }

  // Add child nodes
  for (t_names::const_iterator  it = node.nodenames.begin();
       node.nodenames.end() != it; it++)
  {
    string                      nm = *it;
    t_nodeMap::const_iterator   subNode = node.nodes.find(nm);

    __REQUIRE(node.nodes.end() != subNode);
    __REQUIRE(NULL != subNode->second);

    t_nodeMap::const_iterator   thisNode = nodes.find(nm);

    if (nodes.end() == thisNode)
      add(nm)->merge(*(subNode->second));
    else
      thisNode->second->merge(*(subNode->second));
  }

  return (this);
}


/**
 * Add an attribute to this node
 * @param theName attribute name
 * @param theValue attribute value
 */
XmlNode*        XmlNode::add(string     theName,
                             string     theValue)
{
#ifdef __DEBUG_XML__

    cout << "\t" << "add> attribute to '" << name << "', '"
         << theName << "' = '" << theValue << "'" << endl;
#endif // __DEBUG_XML__

  XmlNode* n = nodes[theName];

  if (NULL == n)
    attributes.push_back(theName);
  else
    delete (n);

  n = new XmlNode(theName, this);
  n->setValue(theValue);
  nodes[theName]=n;
  return (n);
}

/**
 * Add an attribute to this node
 * @param theName attribute name
 * @param theValue attribute value
 */
XmlNode*        XmlNode::addLong(string         theName,
                                 const long     theValue)
{
#ifdef __DEBUG_XML__
    cout << "\t" << "addLong> attribute to '" << name << "', '"
         << theName << "' = '" << theValue << "'" << endl;
#endif // __DEBUG_XML__

  XmlNode* n = nodes[theName];

  if (NULL == n)
    attributes.push_back(theName);
  else
    delete (n);

  n = new XmlNode(theName, this);
  n->setLong(theValue);
  nodes[theName]=n;
  return (n);
}

/**
 * Add an attribute to this node
 * @param theName attribute name
 * @param theValue attribute value
 */
XmlNode*        XmlNode::addDouble(string     theName,
                                   const double     theValue)
{
#ifdef __DEBUG_XML__

    cout << "\t" << "addDouble> attribute to '" << name << "', '"
         << theName << "' = '" << theValue << "'" << endl;

#endif // __DEBUG_XML__

  // Do some cleaning before
  XmlNode* n = nodes[theName];

  if (NULL == n)
    attributes.push_back(theName);
  else
    delete (n);

  n = new XmlNode(theName, this);
  n->setDouble(theValue);
  nodes[theName]=n;
  return (n);
}

/**
 * Get the occ-th node named theName
 * The Node must exist
 * @param theName the name
 * @param occ number of the node
 * @return found node
 */
XmlNode*        XmlNode::GET(const string&		theName,
                             const unsigned long	occ)
{
  XmlNode* res = get(theName, occ);
  if (res==NULL) {
    __FAIL(str(format("No such node %s with occurence %d")
                   % theName % occ));
  }
  return res;
}

/**
 * Get the occ-th node named theName
 * The Node must exist
 * @param theName the name
 * @param occ number of the node
 * @return found node
 */
const XmlNode*  XmlNode::GET(const string&		theName,
                             const unsigned long	occ) const
{
  const XmlNode* res = get(theName, occ);
  if (res==NULL) {
    __FAIL(str(format("No such node %s with occurence %d")
                   % theName % occ));
  }
  return res;
}

/**
 * Get the occ-th node named theName
 * @param theName the name
 * @param occ number of the node
 * @return found node
 */
XmlNode*        XmlNode::get(const string&		theName,
                             const unsigned long	occ)
{
#ifdef __DEBUG_XML__
    cout << "\t\t" << "begin- get> myName:" << name << ", theName:"<<theName<< endl;
#endif // __DEBUG_XML__

  XmlNode*      res = NULL;
  int           pos = theName.find(".");

  if (pos > 0)
  {
    string              sub = theName.substr(0, pos);
#ifdef __DEBUG_XML__
    cout << "\t\t\t" << "sub=" << sub << endl;
#endif // __DEBUG_XML__

    res = nfind(sub);
    if (res) {
      string              sup = theName.substr(pos + 1);
#ifdef __DEBUG_XML__
    cout << "\t\t\t" << "sup=" << sup<< endl;
#endif // __DEBUG_XML__
      res =  res->get(sup, occ);
    }
  }
  else
  {
    ostringstream       newName;
    newName << theName;
    if (occ > 0)
      newName << "#" << occ;
    res = nfind(newName.str());
  }

#ifdef __DEBUG_XML__
    cout << "\t\t" << "end- get> myName:" << name << ", theName:"<<theName<< endl;
#endif // __DEBUG_XML__

  return (res);
}





/**
 * Get the occ-th node named theName
 * @param theName the name
 * @param occ number of the node
 * @return found node
 */
const XmlNode*  XmlNode::get(const string&		theName,
                             const unsigned long	occ) const
{
#ifdef __DEBUG_XML__

    cout << "\t\t" << "begin- get> myName:" << name << ", theName:"<<theName<< endl;

#endif // __DEBUG_XML__

  const XmlNode*        res = NULL;
  int                   pos = theName.find('.');

  if (pos > 0)
  {
    string              sub = theName.substr(0, pos);

    res = nfind(sub);
    if (res) {
      string              sup = theName.substr(pos + 1);

      res =  res->get(sup, occ);
    }
  }
  else
  {
    ostringstream       newName;

    newName << theName;
    if (occ > 0)
      newName << "#" << occ;
    res = nfind(newName.str());
  }

#ifdef __DEBUG_XML__
    cout << "\t\t" << "end- get> myName:" << name << ", theName:"<<theName<< endl;
#endif // __DEBUG_XML__

  return (res);

}

/**
 * get the node value
 * @return node value
 */
string  XmlNode::get(void) const
{
#ifdef __DEBUG_XML__
    cout << "\t\t" << "get> myName:" << name << ", value:"<<value<< endl;
#endif // __DEBUG_XML__


  return (value);
}

/**
 * create a node from a dotted path "toto.tutu.titi"
 * all intermidiate nodes are created if needed.
 * @param theName dotted path
 * @param occ index of the last name in dotted path
 * @return new node (leaf)
 */
XmlNode*        XmlNode::put(string             theName,
                             unsigned long      occ)
{
  XmlNode * res = NULL;

#ifdef __DEBUG_XML__
    cout << "\t\t" << "put> myName:" << name << ", theName:"<<theName<<", "<<occ<< endl;
#endif // __DEBUG_XML__

  int pos = theName.find('.');

  if (pos > 0)
  {
    string              sub = theName.substr(0,pos);
    string              sup = theName.substr(pos+1);

    res = nfind(sub);
    if (!res)
      res = add(sub);
    res =  res -> put (sup,occ);
  }
  else
  {
    ostringstream       newName;

    newName << theName;
    if (occ > 0)
      newName << "#" << occ;
    res = nfind(newName.str());
    if (!res)
      res = add(newName.str());
  }
  return (res);
}

/**
 * remove a particular node
 * @param name name of the node tob removed (dotted path)
 * @param occ index of the leaf
 */
void    XmlNode::remove(string          theName,
                        unsigned long   occ,
                        bool            del)
{
  XmlNode * res = NULL;
  int pos = theName.find('.');

#ifdef __DEBUG_XML__
    cout << "\t\t" << "remove> myName:" << name << ", theName:"<<theName<<", "
         << occ << endl;
#endif // __DEBUG_XML__

  // There is a point in the name so go to the next level
  if (pos > 0)
  {
    string              sub = theName.substr(0,pos);

    res = nfind(sub);
    if (!res)
      __ERROR ("unknow name: " + theName);
    else
    {
      string              sup = theName.substr(pos+1);
      res->remove(sup, occ, del);
    }

    return;
  }

  // There is no point in the name
  ostringstream       newName;

  newName << theName;
  if (occ > 0)
    newName << "#" << occ;

  t_nodeMap::iterator it = ifind(newName.str());

  if (it == nodes.end())
    __ERROR("unknow name: " + newName.str());
  else
  {
    XmlNode*          n = it->second;

    nodes.erase(it);
    t_names::iterator it2 = find(nodenames.begin(), nodenames.end(),
                                 newName.str());
    if (nodenames.end() != it2)
    {
      string                name = theName;
      unsigned long         nocc = occ + 1;
      t_nodeMap::iterator   nit = ifind(str(format("%s#%d")
                                            % name % nocc));
      while (nit != nodes.end())
      {
        XmlNode*     mem = nit->second;

        nodes.erase(nit);
        if (nocc > 1) {
          nodes[str(format("%s#%d") % name % (nocc - 1))] = mem;
	  mem->name = str(format("%s#%d") % name % (nocc - 1));
	}
        else {
          nodes[name] = mem;
	  mem->name = name;
	}

        nocc++;
        nit = ifind(str(format("%s#%d") % name % nocc));
      }
      if (nocc > 1)
        it2 = find(nodenames.begin(), nodenames.end(),
                   str(format("%s#%d") % name % (nocc - 1)));
      else
        it2 = find(nodenames.begin(), nodenames.end(), name);
      nodenames.erase(it2);
    }
    else
    {
      it2 = find(attributes.begin(), attributes.end(), newName.str());

      if (attributes.end() != it2)
        attributes.erase(it2);
    }
    if (del)
      delete (n);
    n = NULL;
  }
}

/**
 * set the value as a double value
 * @param d value
 */
void    XmlNode::setDouble(double       d)
{
  value = str(format("%f") % d);
}

/**
 * set the value as a lonf value
 * @param l value
 */
void    XmlNode::setLong(long   l)
{
  value = str(format("%d") % l);
}


/**
 * (==) compare two nodes
 * Return true if they are identical
 */
bool        XmlNode::operator==(const XmlNode&       node) const
{
  // Compare some values
  if ((value != node.get() )
      || (attributes.size() != node.attributes.size())
      || (nodenames.size() != node.nodenames.size()))
    return (false);

  // Compare attributes
  for (t_names::const_iterator  it = attributes.begin();
       attributes.end() != it; it++)
  {
    string                      nm = *it;
    t_nodeMap::const_iterator   attrSelf = nodes.find(nm);
    t_nodeMap::const_iterator   attrNode = node.nodes.find(nm);

    __REQUIRE(nodes.end() != attrSelf);

    if (node.nodes.end() == attrNode)
      return (false);

    __REQUIRE(NULL != attrSelf->second);
    __REQUIRE(NULL != attrNode->second);

    if (*attrSelf != *attrNode)
      return (false);
  }

  // Compare nodes
  for (t_names::const_iterator  it = nodenames.begin();
       nodenames.end() != it; it++)
  {
    string                      nm = *it;
    t_nodeMap::const_iterator   nodeSelf = nodes.find(nm);
    t_nodeMap::const_iterator   nodeNode = node.nodes.find(nm);

    __REQUIRE(nodes.end() != nodeSelf);

    if (node.nodes.end() == nodeNode)
      return (false);

    __REQUIRE(NULL != nodeSelf->second);
    __REQUIRE(NULL != nodeNode->second);

    if (*nodeSelf != *nodeNode)
      return (false);
  }

  return (true);
}


/**
 * write to a stream the xml value of this node and children
 * @param stream output
 * @param depth current depth
 */
void    XmlNode::toXML(ostringstream&   stream,
                       unsigned long    depth) const
{

#ifdef __DEBUG_XML__
    cout << "\t" << "toXML> level " << depth << ", size=" << nodes.size()
         << ", name='" << name << "'." << endl;
#endif // __DEBUG_XML__

  string                nm;

  if (depth > 0)
  {
    unsigned int        pos = name.find('#');

    if (string::npos != pos)
      nm = name.substr(0, pos);
    else
      nm = name;

    stream << '<' << nm ;
    for (t_names::const_iterator      at = attributes.begin();
         attributes.end() != at; at++)
    {
      t_nodeMap::const_iterator nit = nodes.find(*at);

      __REQUIRE(nodes.end() != nit);
      const XmlNode*            n = nit->second;

      stream << ' ' << n->getName() << "=\"" << n->get() << '"';
    }
    stream << ">";
  }

  if (size() > 0)
  {
    const unsigned long n_depth = depth + 1;

    for (t_names::const_iterator        it = nodenames.begin();
         nodenames.end() != it; it++)
    {
      string                    nodename = (*it);
      t_names::const_iterator   at =
        find(attributes.begin(), attributes.end(), nodename);

      if (attributes.end() == at)
      {
        t_nodeMap::const_iterator       nit = nodes.find(nodename);

        __REQUIRE(nodes.end() != nit);
        const XmlNode*                  n = nit->second;

        n->toXML(stream, n_depth);
      }
    }
  }

  if (depth > 0)
    stream << value << "</" << nm << '>';

#ifdef __DEBUG_XML__
    cout << "\t\t" << "toXML> going down " << stream.str() << endl;

#endif // __DEBUG_XML__

}

/** Start something */
void    XmlParser::startElement(const XML_Char*         name,
                                const XML_Char**        attr)
{
  XmlNode*      n = current->add(name);
  //cout << "start elt: "<< name << endl;
  for (unsigned int     i = 0; attr[i]; i += 2) {
    n->add(attr[i], attr[i+1]);
    //cout << "\t* " << attr[i] << "--" << attr[i+1] << endl;
  }
  current = n;
}

/** End something */
void    XmlParser::endElement(const XML_Char*   /*name*/)
{
  XmlNode*      parent = current->getParent();

  if (parent)
    current = parent;

  //cout << "end elt: "<< name << endl;

}


/** ValueOf something */
void    XmlParser::charData(const XML_Char*     val,
                            int                 len)
{
  if (len > 0)
  {
    char*     chr = new char[len + 1];

    chr[len] = 0;
    strncpy(chr, val, len);

    string s = current->get();
    s += chr;
    current->setValue(s);
    delete[] (chr);
  }
}

/** constructeur */
XmlParser::XmlParser(XmlNode*   theRoot,
                     string     buff)
{
  expatpp(true);
  root = theRoot;
  current = root;

#ifdef __DEBUG_XML__
    cout << "\t" << "parse: " << buff.size() <<endl;
    cout << "\t\t" << "parse buf: " << buff << endl;
#endif // __DEBUG_XML__

  if (!XML_Parse(buff.c_str(), buff.size(), 1))
  {
    cout <<  "parse erreur code " << XML_GetErrorCode() << ": "
         << XML_ErrorString(XML_GetErrorCode()) << endl;

    __FAIL("parse error ("+buff+")");
  }

#ifdef __DEBUG_XML__
    cout << "\t" << "eof parse\n";
#endif // __DEBUG_XML__

}

/** destructeur */
XmlParser::~XmlParser(void)
{
  //expatpp::~expatpp(); TO DO ?
}

/** initialise method */
void    Xml::initialize(void)
{
  root = new XmlNode("root", NULL);
}

/**
 * empty constructor
 */
Xml::Xml(void)
{
  initialize();
}

/**
 * constructor with input
 * @param buffer xml string
 * @param isFile is the input a file ?
 */
Xml::Xml(const string&  buffer,
         bool           isFile)
{
  initialize();

  if (isFile) {
    readFile(buffer);
  }
  else {
    parse(buffer);
  }

}

/** readFile */
void    Xml::readFile(const string&     buffer,
                      bool              fnew)
{

//  ifstream      file(buffer.c_str());
//  string      data;
//  string      line;

//  if (file.fail())
//    __FAIL("readFile error for " + buffer);
//  while (getline(file, line))
//    data += "\n"+line;

	string data;
	FILE *pFile = NULL;
	pFile = fopen(buffer.c_str(), "r");
	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			char ch = getc(pFile);
			if(ch != EOF && ch != '\t' && ch != '\n' && ch != '\r')
				data += ch;
		}
	}
	else
	{
		__FAIL("readFile error for " + buffer);
	}

  parse(data,fnew);
}

/** destructor */
Xml::~Xml(void)
{
  delete (root);
  root = NULL;
}

/**
 * parse a string
 * @param buff string to be parsed
 */
void    Xml::parse(string       buff,
                   bool         del)
{
  if (del) {
    delete (root);
    root = new XmlNode("root", NULL);
  }

  XmlParser(root, buff);
}

/**
 * Get a node with its name
 * @param r considered root node
 * @param name node name
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::get(XmlNode*		r,
                         const string&		name,
                         const unsigned long	occ)
{
  XmlNode*      n = r->get(name,occ);
  return (n);
}

const XmlNode*  Xml::get(XmlNode*		r,
                         const string&		name,
                         const unsigned long	occ) const
{
  XmlNode*      n = r->get(name,occ);
  return (n);
}

/**
 * Get a node with its name
 * The node must exist
 * @param r considered root node
 * @param name node name
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::GET(XmlNode*		r,
                         const string&		name,
                         const unsigned long	occ)
{
  XmlNode*      n = r->GET(name,occ);
  return (n);
}

const XmlNode*  Xml::GET(XmlNode*		r,
                         const string&		name,
                         const unsigned long	occ) const
{
  XmlNode*      n = r->GET(name,occ);
  return (n);
}

/**
 * get an attribute from a node from the root
 * @param r considered root node
 * @param node dotted path of the node
 * @param attr attribute name
 * @param occ leaf index
 * @return node
 */
string  Xml::get(XmlNode*		r,
                 const string&		node,
                 const string&		attr,
                 const unsigned long	occ) const
{
  __REQUIRE(NULL != r);

  const XmlNode*        ch = r->get(node, occ);

  if (NULL == ch)
  {
    __FAIL("Node " + node + " does not exists when retrieving attribute "
               + attr + ".");
    return ("");
  }

  return (ch->get());
}


/**
 * get a node from the root
 * @param name dotted path of the node
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::GET(const string&		name,
                         const unsigned long	occ)
{
  return (GET(root, name, occ));
}

const XmlNode*  Xml::GET(const string&		name,
                         const unsigned long	occ) const
{
  return (GET(root, name, occ));
}

/**
 * get a node from the root
 * @param name dotted path of the node
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::get(const string&		name,
                         const unsigned long	occ)
{
  return (get(root, name, occ));
}

const XmlNode*  Xml::get(const string&		name,
                         const unsigned long	occ) const
{
  return (get(root, name, occ));
}

/**
 * get an attribute from a node from the root
 * @param node dotted path of the node
 * @param attr attribute name
 * @param occ leaf index
 * @return node
 */
string  Xml::get(const string&		node,
                 const string&		attr,
                 const unsigned long	occ) const
{
  return (get(root, node, attr, occ));
}



/**
 * put or replace a node
 * @param r considered root node
 * @param name node name
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::put(XmlNode*       r,
                         string         name,
                         unsigned long  occ)
{
  XmlNode*      n = r->put(name, occ);

  if (n)
    return (n);
  else
  {
    __FAIL("can't create name ("+name+")");
    return (NULL);
  }
}

/**
 * put or replace an attribut from a node
 * @param r considered root node
 * @param node node name
 * @param attr attribut name
 * @param val attribut value
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::put(XmlNode*       r,
                         string         name,
                         string         attr,
                         string         val,
                         unsigned long  occ)
{
  XmlNode*      n = r->put(name, occ);

  if (NULL != n)
  {
    n->add(attr, val);
    return (n);
  }
  else
  {
    __FAIL("can't create name ("+name+")");
    return (NULL);
  }
}


/**
 * put or replace a node from root
 * @param name node name
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::put(string         name,
                         unsigned long   occ)
{
  return (put(root, name, occ));
}

/**
 * put or replace a node from root
 * @param node node name
 * @param attr attribut name
 * @param val attribut value
 * @param occ leaf index
 * @return node
 */
XmlNode*        Xml::put(string         name,
                         string         attr,
                         string         val,
                         unsigned long  occ)
{
#ifdef __DEBUG_XML__
    cout << "\t\t" << "Xml::put: " << name << "," << attr << "," << val << endl;
#endif // __DEBUG_XML__

  return (put(root, name, attr, val, occ));
}

/**
 * remove a node
 * /!\ remove does not keep the order of the elements with the same name /!\
 * @param name of the node to be removed
 * @param occ index
 * @param del true if the node has to be deleted
 */
void    Xml::remove(string              name,
                    unsigned long       occ,
                    bool                del)
{
  root->remove(name, occ, del);
}

/**
 * get an XML string of this message
 * @return string
 */
string  Xml::toXML(void) const
{
  ostringstream stream;

#ifdef __DEBUG_XML__
    cout << "\t\t" << "toXML> begin." << endl;
#endif // __DEBUG_XML__

  root->toXML(stream, 0);

#ifdef __DEBUG_XML__
    cout << "\t\t" << "toXML> end." << endl ;
#endif // __DEBUG_XML__

  return (stream.str());
}
}
