# ifndef __XML_H__
# define __XML_H__

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <map>
# include <vector>
# include <list>
# include <boost/lexical_cast.hpp>

# include "tests.hpp"
# include "expatpp.hpp"

using namespace std;
using boost::lexical_cast;
using boost::bad_lexical_cast;
namespace generated {
class XmlNode
{
  public:
    /*
    ** typedef for eye candy
    */
    typedef map<string, XmlNode*>       t_nodeMap;
    typedef vector<string>              t_names;

  private:

    /** Data */

    // list of children
    t_nodeMap           nodes;
    t_names             nodenames;

    // list of attributes
    t_names             attributes;

    // this node father
    XmlNode*            parent;

    // this node name
    string              name;

    // this node value
    string              value;

    /**
     * find a child or attribute with an dotted path
     * @param key dotted path
     * @return node found
     */
    inline XmlNode*            nfind(string    key)
    {
      t_nodeMap::const_iterator it = nodes.find(key);

      if (nodes.end() != it)
        return it->second;
      else
        return NULL;
    }

    const XmlNode*      nfind(string    key) const
    {
      t_nodeMap::const_iterator it = nodes.find(key);

      if (nodes.end() != it)
        return it->second;
      else
        return NULL;
    }


    /**
     * find a child or attribute with an dotted path
     * @param key dotted path
     * @return iterator on found node
     */
    inline t_nodeMap::iterator         ifind(string    key)
    {
      t_nodeMap::iterator it = nodes.find(key);

      if (nodes.end() != it)
        return (it);
      else
        return (nodes.end());
    }

    inline t_nodeMap::const_iterator    ifind(string    key) const
    {
      t_nodeMap::const_iterator it = nodes.find(key);

      if (nodes.end() != it)
        return (it);
      else
        return (nodes.end());
    }


  public:

    /**
     * Constructor
     * @param theName node name
     * @param theParent father node
     */
    XmlNode(string      theName,
            XmlNode*    theParent);

    /**
     * Constructor
     * @param buff is the xml string
     */
    XmlNode(string         buff);

    /**
     * Copy constructor
     * @param node is the node to copy
     */
    XmlNode(const XmlNode&      node);

    /**
     * Empty Constructor
     */
    XmlNode(void);

    /**
     * Destructor
     */
    ~XmlNode();

    /**
     * Get this node name
     * @return node name
     */
    inline string       getName(void) const
    {
      return (name);
    }

    /**
     * Get this node name
     * @return node name
     */
    inline string       getNameWithoutOcc(void) const
    {
       const int pos = name.find('#');
       if (-1 == pos)
         return (name);
       return (name.substr(0, pos));
    }

     /**
      * Get this node name
      * @return node name
      */
     inline unsigned long        getOccurence(void) const
     {
		bool b = parent != NULL;
       __REQUIRE( b );

       const int pos = name.find('#');

       if (-1 == pos)
         return (0);
       string  occ = name.substr(pos + 1);

       return (lexical_cast<unsigned long>(occ));
     }

    /**
     * set the value of this node
     * @param theValue the value
     */
    void        setValue(string theValue);
    void        setString(string s) { setValue(s); }

    /**
     * Add a child to this node
     * @param theName name of this child
     * @return new child node
     */
    XmlNode* add(string theName);

    /**
     * Add a child to this node
     * @param node is the child node to add
     * @return new child node
     */
    XmlNode* add(XmlNode&       node);
    XmlNode* add(const XmlNode& node);


    /**
     * Merge a node into this one
     * @param node is the child node to add
     * @return new child node
     */
    XmlNode* merge(const XmlNode&       node);


    /**
     * Add an attribute to this node
     * @param theName attribute name
     * @param theValue attribute value
     */
    XmlNode* add(string theName, string theValue);
    XmlNode* addString(string theName, string theValue) { return add(theName, theValue);}
    XmlNode* addLong(string theName, long theValue);
    XmlNode* addDouble(string theName, double theValue);

	/**
	 * Get the occ-th node named theName
	 * The Node must exist
	 * @param theName the name
	 * @param occ number of the node
	 * @return found node
	 */
    const XmlNode* GET(const string&		theName,
		       const unsigned long	occ=0) const;
	XmlNode*       GET(const string&	theName,
			   const unsigned long	occ=0);

    /**
     * pop the first child and return it
     */
    inline XmlNode*    pop(void)
    {
      XmlNode*  node = nodes[nodenames[0]];

      nodes.clear();
      nodenames.clear();
      attributes.clear();

      return (node);
    }


    /**
     * Get the occ-th node named theName
     * @param theName the name
     * @param occ number of the node
     * @return found node
     */
    XmlNode*            get(const string&	theName,
                            unsigned long       occ = 0);
    const XmlNode*      get(const string&	theName,
                            unsigned long       occ = 0) const;

    /**
     * getExistingOrAdd: get the existing node or create  a new one
     * @return the node (existing or created)
     */
    inline XmlNode&	getExistingOrAdd(const string&		theName,
					 const unsigned long	occ = 0)
      {
	XmlNode*	ret = get(theName, occ);

	if (NULL == ret)
	  ret = add(theName);

	__REQUIRE(NULL != ret);
	return (*ret);
      }

    /**
     * (==) compare two nodes
     * Return true if they are identical
     */
    bool        operator==(const XmlNode&       node) const;
    inline bool operator!=(const XmlNode&       node) const
    {
      return (!(*this == node));
    }


    /**
     * get the node value
     * @return node value
     */
    string get(void) const;
    string getString(void) const {  return get(); }
    long getLong(void) const {  return lexical_cast<long>(get()); }
    double getDouble(void) const {  return lexical_cast<double>(get()); }


    /**
     * create a node from a dotted path "toto.tutu.titi"
     * all intermidiate nodes are created if needed.
     * @param theName dotted path
     * @param occ index of the last name in dotted path
     * @return new node (leaf)
     */
    XmlNode*    put(string              theName,
                    unsigned long       occ = 0);

    /**
     * remove a particular node
     * @param name name of the node tob removed (dotted path)
     * @param occ index of the leaf
     * @param del true if the node has to be deleted
     */
    void        remove(string           name,
                       unsigned long    occ = 0,
                       bool             del = false);

    /**
     * Get the father of this node
     * @return father
     */
    inline XmlNode*             getParent(void)
    {
      return (parent);
    }
    inline const XmlNode*       getParent(void) const
    {
      return (parent);
    }

    /**
     * set the value as a double value
     * @param d value
     */
    void        setDouble(double        d);

    /**
     * set the value as a lonf value
     * @param l value
     */
    void        setLong(long    l);

    /**
     * return the number of children tag
     * @return number of children
     */
    unsigned long       size(void) const
    {
      return (nodes.size() - attributes.size());
    }


    /**
     * write to a stream the xml value of this node and children
     * @param stream output
     * @param depth current depth
     */
    void        toXML(ostringstream&    stream,
                      unsigned long     depth) const;

    inline string       toXML(void) const
    {
      ostringstream     stream;

      toXML(stream, 1);
      return (stream.str());
    }


    /**
     * returns the list of all child (node + attr) names
     * @param children list
     */
    void        getChildrenNames(t_names&       children) const;

    /**
     * returns the list of all nodes  names
     * @param children list
     */
    void        getNodes(t_names&  thenodes) const;


    /**
     * returns a constant iterator over the start of the list of children
     */
    inline t_names::const_iterator      nodesIterator(void) const
    {
      return (nodenames.begin());
    }

    /**
     * returns a constant iterator over the end  of the list of children
     */
    inline t_names::const_iterator      nodesEnd(void) const
    {
      return (nodenames.end());
    }

    /**
     * returns the list of all attributes names
     * @param children list
     */
    void        getAttributes(t_names&  attributes) const;

    /**
     * returns a constant iterator over the start of the list of attributes
     */
    inline t_names::const_iterator      attrIterator(void) const
    {
      return (attributes.begin());
    }

    /**
     * returns a constant iterator over the end  of the list of attributes
     */
    inline t_names::const_iterator      attrEnd(void) const
    {
      return (attributes.end());
    }


    static const  XmlNode	empty;
};

class XmlParser : public expatpp {
  private:

    // root of the XML tree
    XmlNode*    root;

    // current node
    XmlNode*    current;

    /** Start something */
    void startElement(const XML_Char*   name,
                      const XML_Char**  attr);

    /** End something */
    void endElement(const XML_Char*     name);


    /** ValueOf something */
    void charData(const XML_Char*       val,
                  int                   len);

  public:

    /** constructor */
    XmlParser(XmlNode*  theRoot,
              string    buffer);

    /** destructor */
    ~XmlParser(void);
};

class Xml {

  private:

    // root of this XML message
    XmlNode*    root;

  public:

    /**
     * empty constructor
     */
    Xml(void);

    /**
     * constructor with input
     * @param buffer xml string
     * @param isFile is the input a file ?
     */
    Xml(const string&    buffer,
        bool             isFile = false);

    /** initialise method */
    void        initialize();

    /** destructor */
    ~Xml(void);

    /**
     * parse an  xml file
     * @param buffer file name
     * @param b new tree ?
     */
    void        readFile(const string&  buffer,
                         bool           b = true);

    /**
     * parse a string
     * @param buff string to be parsed
     * @param b new tree ?
     */
    void        parse(string    buff,
                      bool      b = true);

    /*
    ** Get the root node
    ** @return the root node
    */
    inline XmlNode*    get(void)
    {
      return (root);
    }

    inline const XmlNode*    get(void) const
    {
      return (root);
    }

    /*
    ** Get the root node and set it to null
    ** @return the root node
    */
    inline XmlNode*    pop(void)
    {
      __REQUIRE(NULL != root);

      XmlNode*  temp = root->pop();

      return (temp);
    }


    /**
     * Get a node with its name
     * @param r considered root node
     * @param name node name
     * @param occ leaf index
     * @return node
     */
    XmlNode*    get(XmlNode*            r,
                    const string&	name,
                    const unsigned long	occ = 0);

    const XmlNode*      get(XmlNode*            r,
                            const string&	name,
                            const unsigned long	occ = 0) const;

    /**
     * Get a node with its name
     * @param r considered root node
     * @param name node name
     * @param occ leaf index
     * @return node
     */
    XmlNode*    GET(XmlNode*            r,
                    const string&	name,
                    const unsigned long	occ = 0);

    const XmlNode*      GET(XmlNode*            r,
                            const string&	name,
                            const unsigned long	occ = 0) const;
    /**
     * Get a node with its name
     * @param r considered root node
     * @param node node name
     * @param attr is the attribute name
     * @param occ leaf index
     * @return node
     */
    string      get(XmlNode*            r,
                    const string&	node,
                    const string&	attr,
                    const unsigned long	occ = 0) const;

    /**
     * get a node from the root
     * @param name dotted path of the node
     * @param occ leaf index
     * @return node
     */
    XmlNode*    get(const string&	name,
                    const unsigned long	occ = 0);
    const XmlNode*      get(const string&	name,
                            const unsigned long	occ = 0) const;

    /**
     * get a node from the root
	 * the node must exist
     * @param name dotted path of the node
     * @param occ leaf index
     * @return node
     */
    XmlNode*    GET(const string&	name,
                    const unsigned long	occ = 0);
    const XmlNode*      GET(const string&	name,
                            const unsigned long	occ = 0) const;

    /**
     * get an attribute from a node from the root
     * @param node dotted path of the node
     * @param attr attribute name
     * @param occ leaf index
     * @return node
     */
    string      get(const string&       node,
                    const string&       attr,
                    const unsigned long	occ = 0) const;

    /**
     * put or replace a node
     * @param r considered root node
     * @param name node name
     * @param occ leaf index
     * @return node
     */
    XmlNode*    put(XmlNode*            r,
                    string              name,
                    unsigned long       occ = 0);

    /**
     * put or replace a node
     * @param r considered root node
     * @param node node name
     * @param attr attribut name
     * @param val attribut value
     * @param occ leaf index
     * @return node
     */
    XmlNode*    put(XmlNode*            r,
                    string              node,
                    string              attr,
                    string              val,
                    unsigned long       occ = 0);


    /**
     * put or replace a node from root
     * @param name node name
     * @param occ leaf index
     * @return node
     */
    XmlNode*    put(string              name,
                    unsigned long       occ = 0);

    /**
     * put or replace a node from root
     * @param node node name
     * @param attr attribut name
     * @param val attribut value
     * @param occ leaf index
     * @return node
     */
    XmlNode*    put(string              name,
                    string              attr,
                    string              val,
                    unsigned long       occ = 0);

    /**
     * remove a node
     * /!\ remove does not keep the order of the elements with the same name /!\
     * @param name of the node to be removed
     * @param occ index
     * @param del true if the node has to be deleted
     */
    void        remove(string           name,
                       unsigned long    occ = 0,
                       bool             del = true);

    /**
     * get an XML string of this message
     * @return string
     */
    string      toXML(void) const;

};
}

#endif /* __XML_H__ */
