#include <vle/value.hpp>
#include <vle/devs.hpp>
#include <vle/utils/DateTime.hpp>
#include <vle/utils/Trace.hpp>
#include <TypeDefs.h>
#include <TypeDefs_Values.h>
#include <boost/function.hpp>
#include "Compatibility.hpp"
#include "FunctionDirectory.hpp"
#include "FunctionLibrary.hpp"

namespace vd = vle::devs;
namespace vv = vle::value;
namespace vu = vle::utils;

namespace generated {

class Communications : public vd::Dynamics {

private:
	
	// references ----------------------------------------------------------------------------------------------
	Long time;
	Long timestep;
	Long cycle;
	Long NID;
	Pointer networksPtr;
	Long nav_msgCategoryId;
	NetworkMessageList nav_toBeSent;
	NetworkMessageList nav_received;
	Long mms_msgCategoryId;
	NetworkMessageList mms_toBeSent;
	NetworkMessageList mms_received;
	
	
	// parameters ----------------------------------------------------------------------------------------------
	
	Logical bfalse;		
	Logical btrue;		
	Long initialized;		
	NetworkMessageDeliveryReports reports;		
	EquipmentStatusList statusList;		
	
	
	// states ---------------------------------------------------------------------------------------------------
	
	enum EModelState_State {
		Initial,
		INIT,
		RUNNING
	 };
	EModelState_State _ModelState_state;
	
	
	// function pointers ----------------------------------------------------------------------------------------------
	
		boost::function<void (const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageDeliveryReports& reports, const Long& nav_msgCategoryId, const NetworkMessageList& nav_toBeSent, NetworkMessageList& nav_rcvd, const Long& mms_msgCategoryId, const NetworkMessageList& mms_toBeSent, NetworkMessageList& mms_rcvd)> _commsManagement;
	
	
	// interactions ----------------------------------------------------------------------------------------------
	
	void interaction_commsManagement(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications::interaction_commsManagement - request at time : " + time.toString());
		try
		{
			_commsManagement(this->time,this->timestep,this->NID,this->statusList,this->networksPtr,this->initialized,this->reports,this->nav_msgCategoryId,this->nav_toBeSent,this->nav_received,this->mms_msgCategoryId,this->mms_toBeSent,this->mms_received);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications::interaction_commsManagement - Error in calling function commsManagement at time : " + time.toString());
		}
	}
	
	
	// events -------------------------------------------------------------------------------------------------------
	
	bool guard_initializing(const vd::Time& time) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications::guard_initializing - request at time : " + time.toString());
		bool result = true;
		result &= (this->time==0); 
		return result;
	};
	
	// Signal  -------------------------------------------------------------------------------------------------------
	
	bool _signal_test2;
	void action_test2 (const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications::action_test2 - request at time : " + time.toString());
		this->_signal_test2 = true; }
	
	// Transitions -------------------------------------------------------------------------------------------------------
	
	void transition_INIT_to_RUNNING_for_ModelState(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications::transition_INIT_to_RUNNING_for_ModelState] - request at time : " + time.toString());
		if(guard_initializing(time)) {
			action_test2(time);
			this->_ModelState_state = RUNNING;
		}
	}
	

public:
	
	// Constructor -------------------------------------------------------------------------------------------------------
	
	Communications(const vd::DynamicsInit& init, const vd::InitEventList& events) : vd::Dynamics(init, events) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications::Communications");
		this->_signal_test2 = false;
		this->_ModelState_state = Initial;
	} 
	
	// Destructor -------------------------------------------------------------------------------------------------------
	
	virtual ~Communications() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications::~Communications");
	}
	
	// Init -------------------------------------------------------------------------------------------------------
	
	virtual vd::Time init(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications - Init at time : " + time.toString());
	
	_commsManagement = (void (*)(const Long& time, const Long& timestep, const Long& nid, const EquipmentStatusList& statusList, const Pointer& networksPtr, Long& initialized, NetworkMessageDeliveryReports& reports, const Long& nav_msgCategoryId, const NetworkMessageList& nav_toBeSent, NetworkMessageList& nav_rcvd, const Long& mms_msgCategoryId, const NetworkMessageList& mms_toBeSent, NetworkMessageList& mms_rcvd)) _pFuncDirectory->getFunction("commsManagement");
	
	
		this->time = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"time\" to \"0\" at time : " + time.toString());
		this->timestep = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"timestep\" to \"0\" at time : " + time.toString());
		this->cycle = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"cycle\" to \"0\" at time : " + time.toString());
		this->NID = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"NID\" to \"0\" at time : " + time.toString());
		this->networksPtr = NULL;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"networksPtr\" to \"NULL\" at time : " + time.toString());
		this->nav_msgCategoryId = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"nav_msgCategoryId\" to \"0\" at time : " + time.toString());
		this->mms_msgCategoryId = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"mms_msgCategoryId\" to \"0\" at time : " + time.toString());
	this->timestep = 1;
	this->time = 0;
	return vd::Time(0.0);
	}
	
	// Output -------------------------------------------------------------------------------------------------------
	
	virtual void output(const vd::Time& time, vd::ExternalEventList& output) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications - Output at time : " + time.toString());
		//Send event on external port (port "OUT")
		vd::ExternalEvent* evt = NULL;
		evt = new vd::ExternalEvent("bfalse");
		if(evt != NULL)
		{
			vv::Value* val = Logical_toValue(this->bfalse);
			if(val != NULL)
			{			
				evt << vd::attribute("bfalse", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port bfalse is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("btrue");
		if(evt != NULL)
		{
			vv::Value* val = Logical_toValue(this->btrue);
			if(val != NULL)
			{			
				evt << vd::attribute("btrue", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port btrue is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("initialized");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->initialized);
			if(val != NULL)
			{			
				evt << vd::attribute("initialized", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port initialized is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("reports");
		if(evt != NULL)
		{
			vv::Value* val = NetworkMessageDeliveryReports_toValue(this->reports);
			if(val != NULL)
			{			
				evt << vd::attribute("reports", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port reports is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("statusList");
		if(evt != NULL)
		{
			vv::Value* val = EquipmentStatusList_toValue(this->statusList);
			if(val != NULL)
			{			
				evt << vd::attribute("statusList", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port statusList is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
	}
	
	// Internal transition -------------------------------------------------------------------------------------------------------
	
	virtual void internalTransition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications - internal transition at time : " + time.toString());
		switch(this->_ModelState_state) {
		case INIT:
			transition_INIT_to_RUNNING_for_ModelState(time);
			
			break;
		case RUNNING:
			interaction_commsManagement(time);
			
			break;
		default:
			this->_ModelState_state = INIT;
		};
	} 
	
	// External transition -------------------------------------------------------------------------------------------------------
	
	virtual void externalTransition(const vd::ExternalEventList& eventList, const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications - externalTransition at time : " + time.toString());
		//Update input port 
	    vd::ExternalEventList::const_iterator it = eventList.begin();
	    for (;it != eventList.end(); it++)
	    {
			const vd::ExternalEvent& event = *(*it);
			if (event.onPort("time"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"time\" port");
				if(event.existAttributeValue("time"))
				{
				    const vv::Value& val = event.getAttributeValue("time");
						
					this->time = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"time\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"time\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"time\" for the port \"time\"");
				}
		    }
			if (event.onPort("timestep"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"timestep\" port");
				if(event.existAttributeValue("timestep"))
				{
				    const vv::Value& val = event.getAttributeValue("timestep");
						
					this->timestep = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"timestep\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"timestep\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"timestep\" for the port \"timestep\"");
				}
		    }
			if (event.onPort("cycle"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"cycle\" port");
				if(event.existAttributeValue("cycle"))
				{
				    const vv::Value& val = event.getAttributeValue("cycle");
						
					this->cycle = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"cycle\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"cycle\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"cycle\" for the port \"cycle\"");
				}
		    }
			if (event.onPort("NID"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"NID\" port");
				if(event.existAttributeValue("NID"))
				{
				    const vv::Value& val = event.getAttributeValue("NID");
						
					this->NID = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"NID\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"NID\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"NID\" for the port \"NID\"");
				}
		    }
			if (event.onPort("networksPtr"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"networksPtr\" port");
				if(event.existAttributeValue("networksPtr"))
				{
				    const vv::Value& val = event.getAttributeValue("networksPtr");
						
					this->networksPtr = Pointer_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"networksPtr\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"networksPtr\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"networksPtr\" for the port \"networksPtr\"");
				}
		    }
			if (event.onPort("nav_msgCategoryId"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"nav_msgCategoryId\" port");
				if(event.existAttributeValue("nav_msgCategoryId"))
				{
				    const vv::Value& val = event.getAttributeValue("nav_msgCategoryId");
						
					this->nav_msgCategoryId = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"nav_msgCategoryId\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"nav_msgCategoryId\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"nav_msgCategoryId\" for the port \"nav_msgCategoryId\"");
				}
		    }
			if (event.onPort("nav_toBeSent"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"nav_toBeSent\" port");
				if(event.existAttributeValue("nav_toBeSent"))
				{
				    const vv::Value& val = event.getAttributeValue("nav_toBeSent");
						
					NetworkMessageList_fromValue(&val, this->nav_toBeSent);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"nav_toBeSent\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"nav_toBeSent\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"nav_toBeSent\" for the port \"nav_toBeSent\"");
				}
		    }
			if (event.onPort("nav_received"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"nav_received\" port");
				if(event.existAttributeValue("nav_received"))
				{
				    const vv::Value& val = event.getAttributeValue("nav_received");
						
					NetworkMessageList_fromValue(&val, this->nav_received);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"nav_received\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"nav_received\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"nav_received\" for the port \"nav_received\"");
				}
		    }
			if (event.onPort("mms_msgCategoryId"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"mms_msgCategoryId\" port");
				if(event.existAttributeValue("mms_msgCategoryId"))
				{
				    const vv::Value& val = event.getAttributeValue("mms_msgCategoryId");
						
					this->mms_msgCategoryId = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"mms_msgCategoryId\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"mms_msgCategoryId\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"mms_msgCategoryId\" for the port \"mms_msgCategoryId\"");
				}
		    }
			if (event.onPort("mms_toBeSent"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"mms_toBeSent\" port");
				if(event.existAttributeValue("mms_toBeSent"))
				{
				    const vv::Value& val = event.getAttributeValue("mms_toBeSent");
						
					NetworkMessageList_fromValue(&val, this->mms_toBeSent);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"mms_toBeSent\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"mms_toBeSent\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"mms_toBeSent\" for the port \"mms_toBeSent\"");
				}
		    }
			if (event.onPort("mms_received"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"mms_received\" port");
				if(event.existAttributeValue("mms_received"))
				{
				    const vv::Value& val = event.getAttributeValue("mms_received");
						
					NetworkMessageList_fromValue(&val, this->mms_received);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"mms_received\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"mms_received\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"mms_received\" for the port \"mms_received\"");
				}
		    }
		}
	}
	
	// observation -------------------------------------------------------------------------------------------------------
	
	virtual vv::Value* observation(const vd::ObservationEvent& event) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Communications - observation");
		return vd::Dynamics::observation(event);
	}
	virtual vd::Time timeAdvance() const
	{
		return vd::Time((double) this->time);
	}
};
}
DECLARE_DYNAMICS(generated::Communications)
