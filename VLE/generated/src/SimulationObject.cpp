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

class SimulationObject : public vd::Dynamics {

private:
	
	// references ----------------------------------------------------------------------------------------------
	Long time;
	Long timestep;
	Long cycle;
	
	
	// parameters ----------------------------------------------------------------------------------------------
	
	Logical bfalse;		
	Logical btrue;		
	Long sideId;		
	String SID;		
	Long NID;		
	EntityType TYPE;		
	Long SUBTYPE;		
	Long SUBSUBTYPE;		
	
	
	// states ---------------------------------------------------------------------------------------------------
	
	enum EModelState_State {
		Initial,
		INIT,
		RUNNING
	 };
	EModelState_State _ModelState_state;
	
	
	// function pointers ----------------------------------------------------------------------------------------------
	
	
	
	// interactions ----------------------------------------------------------------------------------------------
	
	
	
	// events -------------------------------------------------------------------------------------------------------
	
	bool guard_initializing(const vd::Time& time) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject::guard_initializing - request at time : " + time.toString());
		bool result = true;
		result &= (this->time==0); 
		return result;
	};
	
	// Signal  -------------------------------------------------------------------------------------------------------
	
	bool _signal_test2;
	void action_test2 (const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject::action_test2 - request at time : " + time.toString());
		this->_signal_test2 = true; }
	
	// Transitions -------------------------------------------------------------------------------------------------------
	
	void transition_INIT_to_RUNNING_for_ModelState(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject::transition_INIT_to_RUNNING_for_ModelState] - request at time : " + time.toString());
		if(guard_initializing(time)) {
			action_test2(time);
			this->_ModelState_state = RUNNING;
		}
	}
	

public:
	
	// Constructor -------------------------------------------------------------------------------------------------------
	
	SimulationObject(const vd::DynamicsInit& init, const vd::InitEventList& events) : vd::Dynamics(init, events) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject::SimulationObject");
		this->_signal_test2 = false;
		this->_ModelState_state = Initial;
	} 
	
	// Destructor -------------------------------------------------------------------------------------------------------
	
	virtual ~SimulationObject() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject::~SimulationObject");
	}
	
	// Init -------------------------------------------------------------------------------------------------------
	
	virtual vd::Time init(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject - Init at time : " + time.toString());
	
	
	
		this->time = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"time\" to \"0\" at time : " + time.toString());
		this->timestep = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"timestep\" to \"0\" at time : " + time.toString());
		this->cycle = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"cycle\" to \"0\" at time : " + time.toString());
	this->timestep = 1;
	this->time = 0;
	return vd::Time(0.0);
	}
	
	// Output -------------------------------------------------------------------------------------------------------
	
	virtual void output(const vd::Time& time, vd::ExternalEventList& output) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject - Output at time : " + time.toString());
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
		evt = new vd::ExternalEvent("sideId");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->sideId);
			if(val != NULL)
			{			
				evt << vd::attribute("sideId", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port sideId is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("SID");
		if(evt != NULL)
		{
			vv::Value* val = String_toValue(this->SID);
			if(val != NULL)
			{			
				evt << vd::attribute("SID", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port SID is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("NID");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->NID);
			if(val != NULL)
			{			
				evt << vd::attribute("NID", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port NID is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("TYPE");
		if(evt != NULL)
		{
			vv::Value* val = EntityType_toValue(this->TYPE);
			if(val != NULL)
			{			
				evt << vd::attribute("TYPE", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port TYPE is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("SUBTYPE");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->SUBTYPE);
			if(val != NULL)
			{			
				evt << vd::attribute("SUBTYPE", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port SUBTYPE is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("SUBSUBTYPE");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->SUBSUBTYPE);
			if(val != NULL)
			{			
				evt << vd::attribute("SUBSUBTYPE", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port SUBSUBTYPE is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
	}
	
	// Internal transition -------------------------------------------------------------------------------------------------------
	
	virtual void internalTransition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject - internal transition at time : " + time.toString());
		switch(this->_ModelState_state) {
		case INIT:
			transition_INIT_to_RUNNING_for_ModelState(time);
			
			break;
		case RUNNING:
			
			break;
		default:
			this->_ModelState_state = INIT;
		};
	} 
	
	// External transition -------------------------------------------------------------------------------------------------------
	
	virtual void externalTransition(const vd::ExternalEventList& eventList, const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject - externalTransition at time : " + time.toString());
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
		}
	}
	
	// observation -------------------------------------------------------------------------------------------------------
	
	virtual vv::Value* observation(const vd::ObservationEvent& event) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SimulationObject - observation");
		return vd::Dynamics::observation(event);
	}
	virtual vd::Time timeAdvance() const
	{
		return vd::Time((double) this->time);
	}
};
}
DECLARE_DYNAMICS(generated::SimulationObject)
