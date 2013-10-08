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

class Flight : public vd::Dynamics {

private:
	
	// references ----------------------------------------------------------------------------------------------
	Long time;
	Long timestep;
	Long cycle;
	Long NID;
	LocalisationInit loc_init;
	LocalisationState loc_state;
	Long sideId;
	EntityType TYPE;
	Long SUBTYPE;
	EnvironmentInteractions interactions;
	NavigationState nav_state;
	NavigationUpdate mms_nav_update;
	
	
	// parameters ----------------------------------------------------------------------------------------------
	
	Logical bfalse;		
	Logical btrue;		
	SStateVector pstate;		
	
	
	// states ---------------------------------------------------------------------------------------------------
	
	enum EModelState_State {
		Initial,
		INIT,
		RUNNING
	 };
	EModelState_State _ModelState_state;
	
	
	// function pointers ----------------------------------------------------------------------------------------------
	
		boost::function<void (const Long& nid, const Long& timestep, const LocalisationInit& linit, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)> _initFlightAndNavModels;
		boost::function<void (const Long& time, const Long& timestep, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const NavigationUpdate& nav_update, NavigationState& nav_state, SStateVector& ssv, LocalisationState& ls, EnvironmentInteractions& EI)> _updatePosition;
	
	
	// interactions ----------------------------------------------------------------------------------------------
	
	void interaction_initFlightAndNavModels(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::interaction_initFlightAndNavModels - request at time : " + time.toString());
		try
		{
			_initFlightAndNavModels(this->NID,this->timestep,this->loc_init,this->nav_state,this->pstate,this->loc_state);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::interaction_initFlightAndNavModels - Error in calling function initFlightAndNavModels at time : " + time.toString());
		}
	}
	void interaction_updatePosition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::interaction_updatePosition - request at time : " + time.toString());
		try
		{
			_updatePosition(this->time,this->timestep,this->NID,this->sideId,this->TYPE,this->SUBTYPE,this->mms_nav_update,this->nav_state,this->pstate,this->loc_state,this->interactions);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::interaction_updatePosition - Error in calling function updatePosition at time : " + time.toString());
		}
	}
	
	
	// events -------------------------------------------------------------------------------------------------------
	
	bool guard_initializing(const vd::Time& time) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::guard_initializing - request at time : " + time.toString());
		bool result = true;
		result &= (this->time==0); 
		return result;
	};
	
	// Signal  -------------------------------------------------------------------------------------------------------
	
	bool _signal_test2;
	void action_test2 (const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::action_test2 - request at time : " + time.toString());
		this->_signal_test2 = true; }
	
	// Transitions -------------------------------------------------------------------------------------------------------
	
	void transition_INIT_to_RUNNING_for_ModelState(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::transition_INIT_to_RUNNING_for_ModelState] - request at time : " + time.toString());
		if(guard_initializing(time)) {
			action_test2(time);
			this->_ModelState_state = RUNNING;
		}
	}
	

public:
	
	// Constructor -------------------------------------------------------------------------------------------------------
	
	Flight(const vd::DynamicsInit& init, const vd::InitEventList& events) : vd::Dynamics(init, events) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::Flight");
		this->_signal_test2 = false;
		this->_ModelState_state = Initial;
	} 
	
	// Destructor -------------------------------------------------------------------------------------------------------
	
	virtual ~Flight() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight::~Flight");
	}
	
	// Init -------------------------------------------------------------------------------------------------------
	
	virtual vd::Time init(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight - Init at time : " + time.toString());
	
	_initFlightAndNavModels = (void (*)(const Long& nid, const Long& timestep, const LocalisationInit& linit, NavigationState& ns, SStateVector& ssv, LocalisationState& ls)) _pFuncDirectory->getFunction("initFlightAndNavModels");
	_updatePosition = (void (*)(const Long& time, const Long& timestep, const Long& nid, const Long& sideId, const EntityType& type, const Long& subType, const NavigationUpdate& nav_update, NavigationState& nav_state, SStateVector& ssv, LocalisationState& ls, EnvironmentInteractions& EI)) _pFuncDirectory->getFunction("updatePosition");
	
	
		this->time = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"time\" to \"0\" at time : " + time.toString());
		this->timestep = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"timestep\" to \"0\" at time : " + time.toString());
		this->cycle = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"cycle\" to \"0\" at time : " + time.toString());
		this->NID = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"NID\" to \"0\" at time : " + time.toString());
		this->sideId = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"sideId\" to \"0\" at time : " + time.toString());
		this->TYPE = ABSTRACT_ENTITY;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"TYPE\" to \"ABSTRACT_ENTITY\" at time : " + time.toString());
		this->SUBTYPE = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"SUBTYPE\" to \"0\" at time : " + time.toString());
	this->timestep = 1;
	this->time = 0;
	return vd::Time(0.0);
	}
	
	// Output -------------------------------------------------------------------------------------------------------
	
	virtual void output(const vd::Time& time, vd::ExternalEventList& output) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight - Output at time : " + time.toString());
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
		evt = new vd::ExternalEvent("pstate");
		if(evt != NULL)
		{
			vv::Value* val = SStateVector_toValue(this->pstate);
			if(val != NULL)
			{			
				evt << vd::attribute("pstate", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port pstate is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
	}
	
	// Internal transition -------------------------------------------------------------------------------------------------------
	
	virtual void internalTransition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight - internal transition at time : " + time.toString());
		switch(this->_ModelState_state) {
		case INIT:
			transition_INIT_to_RUNNING_for_ModelState(time);
			interaction_initFlightAndNavModels(time);
			
			break;
		case RUNNING:
			interaction_updatePosition(time);
			
			break;
		default:
			this->_ModelState_state = INIT;
		};
	} 
	
	// External transition -------------------------------------------------------------------------------------------------------
	
	virtual void externalTransition(const vd::ExternalEventList& eventList, const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight - externalTransition at time : " + time.toString());
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
			if (event.onPort("sideId"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"sideId\" port");
				if(event.existAttributeValue("sideId"))
				{
				    const vv::Value& val = event.getAttributeValue("sideId");
						
					this->sideId = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"sideId\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"sideId\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"sideId\" for the port \"sideId\"");
				}
		    }
			if (event.onPort("TYPE"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"TYPE\" port");
				if(event.existAttributeValue("TYPE"))
				{
				    const vv::Value& val = event.getAttributeValue("TYPE");
						
					this->TYPE = EntityType_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"TYPE\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"TYPE\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"TYPE\" for the port \"TYPE\"");
				}
		    }
			if (event.onPort("SUBTYPE"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"SUBTYPE\" port");
				if(event.existAttributeValue("SUBTYPE"))
				{
				    const vv::Value& val = event.getAttributeValue("SUBTYPE");
						
					this->SUBTYPE = Long_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"SUBTYPE\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"SUBTYPE\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"SUBTYPE\" for the port \"SUBTYPE\"");
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
			if (event.onPort("nav_state"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"nav_state\" port");
				if(event.existAttributeValue("nav_state"))
				{
				    const vv::Value& val = event.getAttributeValue("nav_state");
						
					NavigationState_fromValue(&val, this->nav_state);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"nav_state\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"nav_state\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"nav_state\" for the port \"nav_state\"");
				}
		    }
			if (event.onPort("mms_nav_update"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"mms_nav_update\" port");
				if(event.existAttributeValue("mms_nav_update"))
				{
				    const vv::Value& val = event.getAttributeValue("mms_nav_update");
						
					NavigationUpdate_fromValue(&val, this->mms_nav_update);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"mms_nav_update\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"mms_nav_update\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"mms_nav_update\" for the port \"mms_nav_update\"");
				}
		    }
		}
	}
	
	// observation -------------------------------------------------------------------------------------------------------
	
	virtual vv::Value* observation(const vd::ObservationEvent& event) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Flight - observation");
		return vd::Dynamics::observation(event);
	}
	virtual vd::Time timeAdvance() const
	{
		return vd::Time((double) this->time);
	}
};
}
DECLARE_DYNAMICS(generated::Flight)
