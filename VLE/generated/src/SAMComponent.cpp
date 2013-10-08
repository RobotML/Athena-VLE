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

class SAMComponent : public vd::Dynamics {

private:
	
	// references ----------------------------------------------------------------------------------------------
	Long time;
	Long timestep;
	Long cycle;
	SAElementStatusList statusList;
	SAElementOrderList ordersList;
	SensorTracks tracks;
	EnvironmentInteractions interactions;
	String distSensorDomainFilePath;
	String distJammerDomainFilePath;
	
	
	// parameters ----------------------------------------------------------------------------------------------
	
	Logical bfalse;		
	Logical btrue;		
	Long sideId;		
	String SID;		
	Long NID;		
	EntityType TYPE;		
	Long SUBTYPE;		
	Long SUBSUBTYPE;		
	Vec3 position;		
	Real hA;		
	Long sensorId;		
	SensorOrders sorders;		
	SensorStatus sstatus;		
	RadarDefinition radarDef;		
	SensorDefinition sensorDef;		
	
	
	// states ---------------------------------------------------------------------------------------------------
	
	enum EModelState_State {
		Initial,
		INIT,
		RUNNING
	 };
	EModelState_State _ModelState_state;
	
	
	// function pointers ----------------------------------------------------------------------------------------------
	
		boost::function<void (const Long& NID, const Real& ha, Vec3& position, const Long& sensorId, const RadarDefinition& radarDef, SensorDefinition& sensorDef, SensorStatus& sstatus, const String& distSensorDomainFilePath, const String& distJammerDomainFilePath)> _pSAMComponentInit;
		boost::function<void (const Long& time, const Long& timestep, const Long& NID, const SensorDefinition& sensorDef, SensorStatus& sstatus, SensorOrders& sorders, EnvironmentInteractions& interactions, SensorTracks& tracks, const Long& sideId, const EntityType& TYPE, const Long& SUBTYPE, const Vec3& position, SAElementStatusList& statusList, const SAElementOrderList& ordersList)> _pSAMComponentStep;
	
	
	// interactions ----------------------------------------------------------------------------------------------
	
	void interaction_pSAMComponentInit(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::interaction_pSAMComponentInit - request at time : " + time.toString());
		try
		{
			_pSAMComponentInit(this->NID,this->hA,this->position,this->sensorId,this->radarDef,this->sensorDef,this->sstatus,this->distSensorDomainFilePath,this->distJammerDomainFilePath);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::interaction_pSAMComponentInit - Error in calling function pSAMComponentInit at time : " + time.toString());
		}
	}
	void interaction_pSAMComponentStep(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::interaction_pSAMComponentStep - request at time : " + time.toString());
		try
		{
			_pSAMComponentStep(this->time,this->timestep,this->NID,this->sensorDef,this->sstatus,this->sorders,this->interactions,this->tracks,this->sideId,this->TYPE,this->SUBTYPE,this->position,this->statusList,this->ordersList);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::interaction_pSAMComponentStep - Error in calling function pSAMComponentStep at time : " + time.toString());
		}
	}
	
	
	// events -------------------------------------------------------------------------------------------------------
	
	bool guard_initializing(const vd::Time& time) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::guard_initializing - request at time : " + time.toString());
		bool result = true;
		result &= (this->time==0); 
		return result;
	};
	
	// Signal  -------------------------------------------------------------------------------------------------------
	
	bool _signal_test2;
	void action_test2 (const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::action_test2 - request at time : " + time.toString());
		this->_signal_test2 = true; }
	
	// Transitions -------------------------------------------------------------------------------------------------------
	
	void transition_INIT_to_RUNNING_for_ModelState(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::transition_INIT_to_RUNNING_for_ModelState] - request at time : " + time.toString());
		if(guard_initializing(time)) {
			action_test2(time);
			this->_ModelState_state = RUNNING;
		}
	}
	

public:
	
	// Constructor -------------------------------------------------------------------------------------------------------
	
	SAMComponent(const vd::DynamicsInit& init, const vd::InitEventList& events) : vd::Dynamics(init, events) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::SAMComponent");
		this->_signal_test2 = false;
		this->_ModelState_state = Initial;
	} 
	
	// Destructor -------------------------------------------------------------------------------------------------------
	
	virtual ~SAMComponent() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent::~SAMComponent");
	}
	
	// Init -------------------------------------------------------------------------------------------------------
	
	virtual vd::Time init(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent - Init at time : " + time.toString());
	
	_pSAMComponentInit = (void (*)(const Long& NID, const Real& ha, Vec3& position, const Long& sensorId, const RadarDefinition& radarDef, SensorDefinition& sensorDef, SensorStatus& sstatus, const String& distSensorDomainFilePath, const String& distJammerDomainFilePath)) _pFuncDirectory->getFunction("pSAMComponentInit");
	_pSAMComponentStep = (void (*)(const Long& time, const Long& timestep, const Long& NID, const SensorDefinition& sensorDef, SensorStatus& sstatus, SensorOrders& sorders, EnvironmentInteractions& interactions, SensorTracks& tracks, const Long& sideId, const EntityType& TYPE, const Long& SUBTYPE, const Vec3& position, SAElementStatusList& statusList, const SAElementOrderList& ordersList)) _pFuncDirectory->getFunction("pSAMComponentStep");
	
	
		this->time = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"time\" to \"0\" at time : " + time.toString());
		this->timestep = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"timestep\" to \"0\" at time : " + time.toString());
		this->cycle = 0;
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"cycle\" to \"0\" at time : " + time.toString());
		this->distSensorDomainFilePath = "";
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"distSensorDomainFilePath\" to \"""\" at time : " + time.toString());
		this->distJammerDomainFilePath = "";
		TraceModel(vu::DateTime::simpleCurrentDate() + " - Initialize reference \"distJammerDomainFilePath\" to \"""\" at time : " + time.toString());
	this->timestep = 1;
	this->time = 0;
	return vd::Time(0.0);
	}
	
	// Output -------------------------------------------------------------------------------------------------------
	
	virtual void output(const vd::Time& time, vd::ExternalEventList& output) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent - Output at time : " + time.toString());
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
		evt = new vd::ExternalEvent("position");
		if(evt != NULL)
		{
			vv::Value* val = Vec3_toValue(this->position);
			if(val != NULL)
			{			
				evt << vd::attribute("position", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port position is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("hA");
		if(evt != NULL)
		{
			vv::Value* val = Real_toValue(this->hA);
			if(val != NULL)
			{			
				evt << vd::attribute("hA", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port hA is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("sensorId");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->sensorId);
			if(val != NULL)
			{			
				evt << vd::attribute("sensorId", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port sensorId is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("sorders");
		if(evt != NULL)
		{
			vv::Value* val = SensorOrders_toValue(this->sorders);
			if(val != NULL)
			{			
				evt << vd::attribute("sorders", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port sorders is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("sstatus");
		if(evt != NULL)
		{
			vv::Value* val = SensorStatus_toValue(this->sstatus);
			if(val != NULL)
			{			
				evt << vd::attribute("sstatus", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port sstatus is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("radarDef");
		if(evt != NULL)
		{
			vv::Value* val = RadarDefinition_toValue(this->radarDef);
			if(val != NULL)
			{			
				evt << vd::attribute("radarDef", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port radarDef is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("sensorDef");
		if(evt != NULL)
		{
			vv::Value* val = SensorDefinition_toValue(this->sensorDef);
			if(val != NULL)
			{			
				evt << vd::attribute("sensorDef", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port sensorDef is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
	}
	
	// Internal transition -------------------------------------------------------------------------------------------------------
	
	virtual void internalTransition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent - internal transition at time : " + time.toString());
		switch(this->_ModelState_state) {
		case INIT:
			transition_INIT_to_RUNNING_for_ModelState(time);
			interaction_pSAMComponentInit(time);
			
			break;
		case RUNNING:
			interaction_pSAMComponentStep(time);
			
			break;
		default:
			this->_ModelState_state = INIT;
		};
	} 
	
	// External transition -------------------------------------------------------------------------------------------------------
	
	virtual void externalTransition(const vd::ExternalEventList& eventList, const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent - externalTransition at time : " + time.toString());
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
			if (event.onPort("statusList"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"statusList\" port");
				if(event.existAttributeValue("statusList"))
				{
				    const vv::Value& val = event.getAttributeValue("statusList");
						
					SAElementStatusList_fromValue(&val, this->statusList);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"statusList\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"statusList\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"statusList\" for the port \"statusList\"");
				}
		    }
			if (event.onPort("ordersList"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"ordersList\" port");
				if(event.existAttributeValue("ordersList"))
				{
				    const vv::Value& val = event.getAttributeValue("ordersList");
						
					SAElementOrderList_fromValue(&val, this->ordersList);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"ordersList\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"ordersList\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"ordersList\" for the port \"ordersList\"");
				}
		    }
			if (event.onPort("tracks"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"tracks\" port");
				if(event.existAttributeValue("tracks"))
				{
				    const vv::Value& val = event.getAttributeValue("tracks");
						
					SensorTracks_fromValue(&val, this->tracks);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"tracks\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"tracks\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"tracks\" for the port \"tracks\"");
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
			if (event.onPort("distSensorDomainFilePath"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"distSensorDomainFilePath\" port");
				if(event.existAttributeValue("distSensorDomainFilePath"))
				{
				    const vv::Value& val = event.getAttributeValue("distSensorDomainFilePath");
						
					this->distSensorDomainFilePath = String_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"distSensorDomainFilePath\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"distSensorDomainFilePath\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"distSensorDomainFilePath\" for the port \"distSensorDomainFilePath\"");
				}
		    }
			if (event.onPort("distJammerDomainFilePath"))
		    {
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Trying to update \"distJammerDomainFilePath\" port");
				if(event.existAttributeValue("distJammerDomainFilePath"))
				{
				    const vv::Value& val = event.getAttributeValue("distJammerDomainFilePath");
						
					this->distJammerDomainFilePath = String_fromValue(&val);
					if(val.isNull() == false)
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - Update \"distJammerDomainFilePath\" input port to \"" + val.writeToString() + "\" at time " + time.toString());
					}
					else
					{
						TraceModel(vu::DateTime::simpleCurrentDate() + " - NULL value for  \"distJammerDomainFilePath\" input port at time " + time.toString());
					}
							
				}
				else
				{
					TraceModel(vu::DateTime::simpleCurrentDate() + " - Unknown attribute value \"distJammerDomainFilePath\" for the port \"distJammerDomainFilePath\"");
				}
		    }
		}
	}
	
	// observation -------------------------------------------------------------------------------------------------------
	
	virtual vv::Value* observation(const vd::ObservationEvent& event) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - SAMComponent - observation");
		return vd::Dynamics::observation(event);
	}
	virtual vd::Time timeAdvance() const
	{
		return vd::Time((double) this->time);
	}
};
}
DECLARE_DYNAMICS(generated::SAMComponent)
