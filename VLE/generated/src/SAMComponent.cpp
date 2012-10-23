#include <vle/value.hpp>
#include <vle/devs.hpp>
#include <TypeDefs.h>
#include <TypeDefs_Values.h>

namespace vd = vle::devs;
namespace vv = vle::value;

namespace generated {

class SAMComponent : public vd::Dynamics
{
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

public:

	/**
	 *
	 */
    SAMComponent(const vd::DynamicsInit& init, const vd::InitEventList& events)
        : vd::Dynamics(init, events)
    {
    }

	/**
	 *
	 */
    virtual ~SAMComponent()
    {
    }

	/**
	 *
	 */
    virtual vd::Time init(const vd::Time& /*time*/)
    {
        return vd::Time(1);
    }

	/**
	 *
	 */
    virtual void output(const vd::Time& /*time*/,
                        vd::ExternalEventList& /*output*/) const
    {
    }

	/**
	 *
	 */
    virtual vd::Time timeAdvance() const
    {
        return vd::Time(1);
    }

	/**
	 *
	 */
    virtual void internalTransition(const vd::Time& /*time*/)
    {
    }

	/**
	 *
	 */
    virtual void externalTransition(const vd::ExternalEventList& eventList,
                                    const vd::Time& /*time*/)
    {
        vd::ExternalEventList::const_iterator it = eventList.begin();
        for (;it != eventList.end(); it++)
        {
			const vd::ExternalEvent& event = *(*it);
            // 
            if (event.onPort("time"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				time = Long_fromValue(&val);
            }
            // 
            if (event.onPort("timestep"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				timestep = Long_fromValue(&val);
            }
            // 
            if (event.onPort("cycle"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				cycle = Long_fromValue(&val);
            }
            // 
            if (event.onPort("statusList"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				SAElementStatusList_fromValue(&val, statusList);
            }
            // 
            if (event.onPort("ordersList"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				SAElementOrderList_fromValue(&val, ordersList);
            }
            // 
            if (event.onPort("tracks"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				SensorTracks_fromValue(&val, tracks);
            }
            // 
            if (event.onPort("interactions"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				EnvironmentInteractions_fromValue(&val, interactions);
            }
            // 
            if (event.onPort("distSensorDomainFilePath"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				distSensorDomainFilePath = String_fromValue(&val);
            }
            // 
            if (event.onPort("distJammerDomainFilePath"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				distJammerDomainFilePath = String_fromValue(&val);
            }
		}
    }

	/**
	 *
	 */
    virtual void confluentTransitions(const vd::Time& time,
                                      const vd::ExternalEventList& events)
    {
        internalTransition(time);
        externalTransition(events, time);
    }

	/**
	 *
	 */
    virtual void request(const vd::RequestEvent& /*event*/,
                         const vd::Time& /*time*/,
                         vd::ExternalEventList& /*output*/) const
    {
    }

	/**
	 *
	 */
    virtual vv::Value* observation(const vd::ObservationEvent& /*event*/) const
    {
        return 0;
    }

	/**
	 *
	 */
    virtual void finish()
    {
    }

};
} // namespace generated

DECLARE_DYNAMICS(generated::SAMComponent)