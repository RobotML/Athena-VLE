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

class Root : public vd::Dynamics {

private:
	
	// references ----------------------------------------------------------------------------------------------
	
	
	// parameters ----------------------------------------------------------------------------------------------
	
	Long cycle;		
	Long time;		
	Long timestep;		
	Long interactionCleanningTimeStep;		
	EnvironmentInteractions interactions;		
	String distSensorDomainFilePath;		
	String distJammerDomainFilePath;		
	NetworkDefinitions networkDefs;		
	JammerDefinitions jammerDefs;		
	LocDefinitions locDefs;		
	NetworkList networkList;		
	Pointer networksPtr;		
	
	
	// states ---------------------------------------------------------------------------------------------------
	
	enum EModelState_State {
		Initial,
		INIT,
		RUNNING
	 };
	EModelState_State _ModelState_state;
	
	
	// function pointers ----------------------------------------------------------------------------------------------
	
		boost::function<void (Long& time, const Long& timestep, Long& cycle, const Long& interactionCleanningTimeStep, NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr, EnvironmentInteractions& interactions)> _pRootInit;
		boost::function<void (Long& time, const Long& timestep, Long& cycle, const Pointer& networksPtr, const Long& interactionCleanningTimeStep, EnvironmentInteractions& interactions)> _pRootStep;
	
	
	// interactions ----------------------------------------------------------------------------------------------
	
	void interaction_pRootInit(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::interaction_pRootInit - request at time : " + time.toString());
		try
		{
			_pRootInit(this->time,this->timestep,this->cycle,this->interactionCleanningTimeStep,this->networkDefs,this->networkList,this->networksPtr,this->interactions);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::interaction_pRootInit - Error in calling function pRootInit at time : " + time.toString());
		}
	}
	void interaction_pRootStep(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::interaction_pRootStep - request at time : " + time.toString());
		try
		{
			_pRootStep(this->time,this->timestep,this->cycle,this->networksPtr,this->interactionCleanningTimeStep,this->interactions);
		}
		catch(...)
		{
			TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::interaction_pRootStep - Error in calling function pRootStep at time : " + time.toString());
		}
	}
	
	
	// events -------------------------------------------------------------------------------------------------------
	
	bool guard_initializing(const vd::Time& time) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::guard_initializing - request at time : " + time.toString());
		bool result = true;
		result &= (this->time==0); 
		return result;
	};
	
	// Signal  -------------------------------------------------------------------------------------------------------
	
	
	// Transitions -------------------------------------------------------------------------------------------------------
	
	void transition_INIT_to_RUNNING_for_ModelState(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::transition_INIT_to_RUNNING_for_ModelState] - request at time : " + time.toString());
		this->_ModelState_state = guard_initializing(time) ? RUNNING : INIT;
	}
	

public:
	
	// Constructor -------------------------------------------------------------------------------------------------------
	
	Root(const vd::DynamicsInit& init, const vd::InitEventList& events) : vd::Dynamics(init, events) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::Root");
		this->_ModelState_state = Initial;
	} 
	
	// Destructor -------------------------------------------------------------------------------------------------------
	
	virtual ~Root() {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root::~Root");
	}
	
	// Init -------------------------------------------------------------------------------------------------------
	
	virtual vd::Time init(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root - Init at time : " + time.toString());
	
	_pRootInit = (void (*)(Long& time, const Long& timestep, Long& cycle, const Long& interactionCleanningTimeStep, NetworkDefinitions& networkDefs, const NetworkList& networkList, Pointer& networksPtr, EnvironmentInteractions& interactions)) _pFuncDirectory->getFunction("pRootInit");
	_pRootStep = (void (*)(Long& time, const Long& timestep, Long& cycle, const Pointer& networksPtr, const Long& interactionCleanningTimeStep, EnvironmentInteractions& interactions)) _pFuncDirectory->getFunction("pRootStep");
	
	
	this->timestep = 1;
	this->time = 0;
	return vd::Time(0.0);
	}
	
	// Output -------------------------------------------------------------------------------------------------------
	
	virtual void output(const vd::Time& time, vd::ExternalEventList& output) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root - Output at time : " + time.toString());
		//Send event on external port (port "OUT")
		vd::ExternalEvent* evt = NULL;
		evt = new vd::ExternalEvent("cycle");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->cycle);
			if(val != NULL)
			{			
				evt << vd::attribute("cycle", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port cycle is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("time");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->time);
			if(val != NULL)
			{			
				evt << vd::attribute("time", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port time is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("timestep");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->timestep);
			if(val != NULL)
			{			
				evt << vd::attribute("timestep", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port timestep is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("interactionCleanningTimeStep");
		if(evt != NULL)
		{
			vv::Value* val = Long_toValue(this->interactionCleanningTimeStep);
			if(val != NULL)
			{			
				evt << vd::attribute("interactionCleanningTimeStep", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port interactionCleanningTimeStep is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("interactions");
		if(evt != NULL)
		{
			vv::Value* val = EnvironmentInteractions_toValue(this->interactions);
			if(val != NULL)
			{			
				evt << vd::attribute("interactions", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port interactions is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("distSensorDomainFilePath");
		if(evt != NULL)
		{
			vv::Value* val = String_toValue(this->distSensorDomainFilePath);
			if(val != NULL)
			{			
				evt << vd::attribute("distSensorDomainFilePath", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port distSensorDomainFilePath is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("distJammerDomainFilePath");
		if(evt != NULL)
		{
			vv::Value* val = String_toValue(this->distJammerDomainFilePath);
			if(val != NULL)
			{			
				evt << vd::attribute("distJammerDomainFilePath", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port distJammerDomainFilePath is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("networkDefs");
		if(evt != NULL)
		{
			vv::Value* val = NetworkDefinitions_toValue(this->networkDefs);
			if(val != NULL)
			{			
				evt << vd::attribute("networkDefs", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port networkDefs is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("jammerDefs");
		if(evt != NULL)
		{
			vv::Value* val = JammerDefinitions_toValue(this->jammerDefs);
			if(val != NULL)
			{			
				evt << vd::attribute("jammerDefs", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port jammerDefs is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("locDefs");
		if(evt != NULL)
		{
			vv::Value* val = LocDefinitions_toValue(this->locDefs);
			if(val != NULL)
			{			
				evt << vd::attribute("locDefs", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port locDefs is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("networkList");
		if(evt != NULL)
		{
			vv::Value* val = NetworkList_toValue(this->networkList);
			if(val != NULL)
			{			
				evt << vd::attribute("networkList", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port networkList is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
		evt = new vd::ExternalEvent("networksPtr");
		if(evt != NULL)
		{
			vv::Value* val = Pointer_toValue(this->networksPtr);
			if(val != NULL)
			{			
				evt << vd::attribute("networksPtr", val);
				output.addEvent(evt);
				TraceModel(vu::DateTime::simpleCurrentDate() + " - Output port networksPtr is changed to " + val->writeToString() + " at time " + time.toString());
			}
		} 
	}
	
	// Internal transition -------------------------------------------------------------------------------------------------------
	
	virtual void internalTransition(const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root - internal transition at time : " + time.toString());
		switch(this->_ModelState_state) {
		case INIT:
			transition_INIT_to_RUNNING_for_ModelState(time);
			interaction_pRootInit(time);
			std::cout << this->time << std::endl;
			break;
		case RUNNING:
			interaction_pRootStep(time);
			
			break;
		default:
			this->_ModelState_state = INIT;
		};
	} 
	
	// External transition -------------------------------------------------------------------------------------------------------
	
	virtual void externalTransition(const vd::ExternalEventList& eventList, const vd::Time& time) {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root - externalTransition at time : " + time.toString());
	}
	
	// observation -------------------------------------------------------------------------------------------------------
	
	virtual vv::Value* observation(const vd::ObservationEvent& event) const {
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root - observation");
		return vd::Dynamics::observation(event);
	}

	virtual vd::Time timeAdvance() const
	{
		TraceAlways(vu::DateTime::simpleCurrentDate() + " - Root - Time advance for : " + vd::Time((double)this->time).toString());
		std::cout << "timeAdvance = " << this->time << std::endl;
		return vd::Time((double) this->time);
	}
};
}
DECLARE_DYNAMICS(generated::Root)
