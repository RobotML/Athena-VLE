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

class Localisation : public vd::Dynamics {

private:
	
	// references ----------------------------------------------------------------------------------------------
	Long time;
	Long timestep;
	Long cycle;
	Long NID;
	LocalisationInit loc_init;
	LocalisationState loc_state;
	LocDefinitions locDefs;
	
	
	// parameters ----------------------------------------------------------------------------------------------
	
	Logical bfalse;		
	Logical btrue;		
	Long loc_const_id;		
	LocalisationConst loc_const;		
	LocalisationError loc_error;		
	LocalisationEquipmentState loc_eqp_state;		
	
	
	// states ---------------------------------------------------------------------------------------------------
	
	enum EModelState_State {
		Initial,
		INIT,
		RUNNING
	 };
	EModelState_State _ModelState_state;
	
	
	// function pointers ----------------------------------------------------------------------------------------------
	
		boost::function<void (const Long& nid, const Long& loc_const_id, LocDefinitions& loc_def, LocalisationConst& lconst, LocalisationEquipmentState& leqps, LocalisationError& lerror)> _initLocalisation;
		boost::function<void (const Long& time, const Long& timestep, const Long& nid, const LocalisationConst& lconst, LocalisationEquipmentState& leqps, const LocalisationState& lstate, LocalisationError& lerror)> _stepLocalisation;
	
	
	// interactions ----------------------------------------------------------------------------------------------
	
	void interaction_initLocalisation(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::interaction_initLocalisation - request at time : " + time.toString());
		try
		{
			_initLocalisation(this->NID,this->loc_const_id,this->locDefs,this->loc_const,this->loc_eqp_state,this->loc_error);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::interaction_initLocalisation - Error in calling function initLocalisation at time : " + time.toString());
		}
	}
	void interaction_stepLocalisation(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::interaction_stepLocalisation - request at time : " + time.toString());
		try
		{
			_stepLocalisation(this->time,this->timestep,this->NID,this->loc_const,this->loc_eqp_state,this->loc_state,this->loc_error);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::interaction_stepLocalisation - Error in calling function stepLocalisation at time : " + time.toString());
		}
	}
	
	
	// events -------------------------------------------------------------------------------------------------------
	
	bool guard_initializing(const vd::Time& time) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::guard_initializing - request at time : " + time.toString());
		bool result = true;
		result &= (this->time==0); 
		return result;
	};
	
	// Signal  -------------------------------------------------------------------------------------------------------
	
	bool _signal_test2;
	void action_test2 (const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::action_test2 - request at time : " + time.toString());
		this->_signal_test2 = true; }
	
	// Transitions -------------------------------------------------------------------------------------------------------
	
	void transition_INIT_to_RUNNING_for_ModelState(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::transition_INIT_to_RUNNING_for_ModelState] - request at time : " + time.toString());
		if(guard_initializing(time)) {
			action_test2(time);
			this->_ModelState_state = RUNNING;
		}
	}
	

public:
	
	// Constructor -------------------------------------------------------------------------------------------------------
	
	Localisation(const vd::DynamicsInit& init, const vd::InitEventList& events) : vd::Dynamics(init, events) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::Localisation");
		this->_signal_test2 = false;
		this->_ModelState_state = Initial;
	} 
	
	// Destructor -------------------------------------------------------------------------------------------------------
	
	virtual ~Localisation() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation::~Localisation");
	}
	
	// Init -------------------------------------------------------------------------------------------------------
	
	virtual vd::Time init(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation - Init at time : " + time.toString());
	
	_initLocalisation = (void (*)(const Long& nid, const Long& loc_const_id, LocDefinitions& loc_def, LocalisationConst& lconst, LocalisationEquipmentState& leqps, LocalisationError& lerror)) _pFuncDirectory->getFunction("initLocalisation");
	_stepLocalisation = (void (*)(const Long& time, const Long& timestep, const Long& nid, const LocalisationConst& lconst, LocalisationEquipmentState& leqps, const LocalisationState& lstate, LocalisationError& lerror)) _pFuncDirectory->getFunction("stepLocalisation");
	
	
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
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation - Output at time : " + time.toString());
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
		evt = new vd::ExternalEvent("loc_const_id");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->loc_const_id);
			if(val != NULL)
			{			
				evt << vd::attribute("loc_const_id", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port loc_const_id is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("loc_const");
		if(evt != NULL)
		{
			vv::Value* val = LocalisationConst_toValue(this->loc_const);
			if(val != NULL)
			{			
				evt << vd::attribute("loc_const", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port loc_const is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("loc_error");
		if(evt != NULL)
		{
			vv::Value* val = LocalisationError_toValue(this->loc_error);
			if(val != NULL)
			{			
				evt << vd::attribute("loc_error", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port loc_error is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("loc_eqp_state");
		if(evt != NULL)
		{
			vv::Value* val = LocalisationEquipmentState_toValue(this->loc_eqp_state);
			if(val != NULL)
			{			
				evt << vd::attribute("loc_eqp_state", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port loc_eqp_state is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
	}
	
	// Internal transition -------------------------------------------------------------------------------------------------------
	
	virtual void internalTransition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation - internal transition at time : " + time.toString());
		switch(this->_ModelState_state) {
		case INIT:
			transition_INIT_to_RUNNING_for_ModelState(time);
			interaction_initLocalisation(time);
			
			break;
		case RUNNING:
			interaction_stepLocalisation(time);
			
			break;
		default:
			this->_ModelState_state = INIT;
		};
	} 
	
	// External transition -------------------------------------------------------------------------------------------------------
	
	virtual void externalTransition(const vd::ExternalEventList& eventList, const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation - externalTransition at time : " + time.toString());
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
			if (event.onPort("loc_init"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"loc_init\" port");
				if(event.existAttributeValue("loc_init"))
				{
				    const vv::Value& val = event.getAttributeValue("loc_init");
						
					LocalisationInit_fromValue(&val, this->loc_init);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"loc_init\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"loc_init\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"loc_init\" for the port \"loc_init\"");
				}
		    }
			if (event.onPort("loc_state"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"loc_state\" port");
				if(event.existAttributeValue("loc_state"))
				{
				    const vv::Value& val = event.getAttributeValue("loc_state");
						
					LocalisationState_fromValue(&val, this->loc_state);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"loc_state\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"loc_state\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"loc_state\" for the port \"loc_state\"");
				}
		    }
			if (event.onPort("locDefs"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"locDefs\" port");
				if(event.existAttributeValue("locDefs"))
				{
				    const vv::Value& val = event.getAttributeValue("locDefs");
						
					LocDefinitions_fromValue(&val, this->locDefs);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"locDefs\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"locDefs\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"locDefs\" for the port \"locDefs\"");
				}
		    }
		}
	}
	
	// observation -------------------------------------------------------------------------------------------------------
	
	virtual vv::Value* observation(const vd::ObservationEvent& event) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Localisation - observation");
		return vd::Dynamics::observation(event);
	}
	virtual vd::Time timeAdvance() const
	{
		return vd::Time((double) this->time);
	}
};
}
DECLARE_DYNAMICS(generated::Localisation)
