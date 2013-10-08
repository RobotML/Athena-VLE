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

class Jammer : public vd::Dynamics {

private:
	
	// references ----------------------------------------------------------------------------------------------
	Long time;
	Long timestep;
	Long cycle;
	Long NID;
	JammerDefinitions jammerDefs;
	JammersStatus jammerStatusList;
	JammersOrders jammerOrderList;
	EnvironmentInteractions interactions;
	
	
	// parameters ----------------------------------------------------------------------------------------------
	
	Logical bfalse;		
	Logical btrue;		
	JammerStatus status;		
	Long jammerId;		
	Long jammerDefId;		
	JammerDefinition jammerDef;		
	
	
	// states ---------------------------------------------------------------------------------------------------
	
	enum EModelState_State {
		Initial,
		INIT,
		RUNNING
	 };
	EModelState_State _ModelState_state;
	
	
	// function pointers ----------------------------------------------------------------------------------------------
	
		boost::function<void (const Long& nid, const Long& jammerId, const Long& jammerDefId, JammerDefinitions& defs, JammerDefinition& def, JammerStatus& s, JammersStatus& stl)> _jammerInit;
		boost::function<void (const Long& time, const Long& timestep, const Long& nid, const JammerDefinition& def, JammerStatus& status, JammersStatus& statusList, const JammersOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI)> _jammerStep;
	
	
	// interactions ----------------------------------------------------------------------------------------------
	
	void interaction_jammerInit(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::interaction_jammerInit - request at time : " + time.toString());
		try
		{
			_jammerInit(this->NID,this->jammerId,this->jammerDefId,this->jammerDefs,this->jammerDef,this->status,this->jammerStatusList);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::interaction_jammerInit - Error in calling function jammerInit at time : " + time.toString());
		}
	}
	void interaction_jammerStep(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::interaction_jammerStep - request at time : " + time.toString());
		try
		{
			_jammerStep(this->time,this->timestep,this->NID,this->jammerDef,this->status,this->jammerStatusList,this->jammerOrderList,this->interactions,this->interactions);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::interaction_jammerStep - Error in calling function jammerStep at time : " + time.toString());
		}
	}
	
	
	// events -------------------------------------------------------------------------------------------------------
	
	bool guard_initializing(const vd::Time& time) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::guard_initializing - request at time : " + time.toString());
		bool result = true;
		result &= (this->time==0); 
		return result;
	};
	
	// Signal  -------------------------------------------------------------------------------------------------------
	
	bool _signal_test2;
	void action_test2 (const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::action_test2 - request at time : " + time.toString());
		this->_signal_test2 = true; }
	
	// Transitions -------------------------------------------------------------------------------------------------------
	
	void transition_INIT_to_RUNNING_for_ModelState(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::transition_INIT_to_RUNNING_for_ModelState] - request at time : " + time.toString());
		if(guard_initializing(time)) {
			action_test2(time);
			this->_ModelState_state = RUNNING;
		}
	}
	

public:
	
	// Constructor -------------------------------------------------------------------------------------------------------
	
	Jammer(const vd::DynamicsInit& init, const vd::InitEventList& events) : vd::Dynamics(init, events) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::Jammer");
		this->_signal_test2 = false;
		this->_ModelState_state = Initial;
	} 
	
	// Destructor -------------------------------------------------------------------------------------------------------
	
	virtual ~Jammer() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer::~Jammer");
	}
	
	// Init -------------------------------------------------------------------------------------------------------
	
	virtual vd::Time init(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer - Init at time : " + time.toString());
	
	_jammerInit = (void (*)(const Long& nid, const Long& jammerId, const Long& jammerDefId, JammerDefinitions& defs, JammerDefinition& def, JammerStatus& s, JammersStatus& stl)) _pFuncDirectory->getFunction("jammerInit");
	_jammerStep = (void (*)(const Long& time, const Long& timestep, const Long& nid, const JammerDefinition& def, JammerStatus& status, JammersStatus& statusList, const JammersOrders& orders, const EnvironmentInteractions& currentEI, EnvironmentInteractions& newEI)) _pFuncDirectory->getFunction("jammerStep");
	
	
		this->time = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"time\" to \"0\" at time : " + time.toString());
		this->timestep = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"timestep\" to \"0\" at time : " + time.toString());
		this->cycle = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"cycle\" to \"0\" at time : " + time.toString());
		this->NID = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"NID\" to \"0\" at time : " + time.toString());
	this->timestep = 1;
	this->time = 0;
	return vd::Time(0.0);
	}
	
	// Output -------------------------------------------------------------------------------------------------------
	
	virtual void output(const vd::Time& time, vd::ExternalEventList& output) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer - Output at time : " + time.toString());
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
		evt = new vd::ExternalEvent("status");
		if(evt != NULL)
		{
			vv::Value* val = JammerStatus_toValue(this->status);
			if(val != NULL)
			{			
				evt << vd::attribute("status", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port status is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("jammerId");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->jammerId);
			if(val != NULL)
			{			
				evt << vd::attribute("jammerId", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port jammerId is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("jammerDefId");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->jammerDefId);
			if(val != NULL)
			{			
				evt << vd::attribute("jammerDefId", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port jammerDefId is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("jammerDef");
		if(evt != NULL)
		{
			vv::Value* val = JammerDefinition_toValue(this->jammerDef);
			if(val != NULL)
			{			
				evt << vd::attribute("jammerDef", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port jammerDef is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
	}
	
	// Internal transition -------------------------------------------------------------------------------------------------------
	
	virtual void internalTransition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer - internal transition at time : " + time.toString());
		switch(this->_ModelState_state) {
		case INIT:
			transition_INIT_to_RUNNING_for_ModelState(time);
			interaction_jammerInit(time);
			
			break;
		case RUNNING:
			interaction_jammerStep(time);
			
			break;
		default:
			this->_ModelState_state = INIT;
		};
	} 
	
	// External transition -------------------------------------------------------------------------------------------------------
	
	virtual void externalTransition(const vd::ExternalEventList& eventList, const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer - externalTransition at time : " + time.toString());
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
			if (event.onPort("jammerDefs"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"jammerDefs\" port");
				if(event.existAttributeValue("jammerDefs"))
				{
				    const vv::Value& val = event.getAttributeValue("jammerDefs");
						
					JammerDefinitions_fromValue(&val, this->jammerDefs);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"jammerDefs\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"jammerDefs\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"jammerDefs\" for the port \"jammerDefs\"");
				}
		    }
			if (event.onPort("jammerStatusList"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"jammerStatusList\" port");
				if(event.existAttributeValue("jammerStatusList"))
				{
				    const vv::Value& val = event.getAttributeValue("jammerStatusList");
						
					JammersStatus_fromValue(&val, this->jammerStatusList);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"jammerStatusList\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"jammerStatusList\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"jammerStatusList\" for the port \"jammerStatusList\"");
				}
		    }
			if (event.onPort("jammerOrderList"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"jammerOrderList\" port");
				if(event.existAttributeValue("jammerOrderList"))
				{
				    const vv::Value& val = event.getAttributeValue("jammerOrderList");
						
					JammersOrders_fromValue(&val, this->jammerOrderList);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"jammerOrderList\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"jammerOrderList\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"jammerOrderList\" for the port \"jammerOrderList\"");
				}
		    }
			if (event.onPort("interactions"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"interactions\" port");
				if(event.existAttributeValue("interactions"))
				{
				    const vv::Value& val = event.getAttributeValue("interactions");
						
					EnvironmentInteractions_fromValue(&val, this->interactions);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"interactions\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"interactions\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"interactions\" for the port \"interactions\"");
				}
		    }
		}
	}
	
	// observation -------------------------------------------------------------------------------------------------------
	
	virtual vv::Value* observation(const vd::ObservationEvent& event) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Jammer - observation");
		return vd::Dynamics::observation(event);
	}
	virtual vd::Time timeAdvance() const
	{
		return vd::Time((double) this->time);
	}
};
}
DECLARE_DYNAMICS(generated::Jammer)
