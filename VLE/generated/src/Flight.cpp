#include <vle/value.hpp>
#include <vle/devs.hpp>
#include <TypeDefs.h>
#include <TypeDefs_Values.h>

namespace vd = vle::devs;
namespace vv = vle::value;

namespace generated {

class Flight : public vd::Dynamics
{
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

public:

	/**
	 *
	 */
    Flight(const vd::DynamicsInit& init, const vd::InitEventList& events)
        : vd::Dynamics(init, events)
    {
    }

	/**
	 *
	 */
    virtual ~Flight()
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
            if (event.onPort("NID"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				NID = Long_fromValue(&val);
            }
            // 
            if (event.onPort("loc_init"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				LocalisationInit_fromValue(&val, loc_init);
            }
            // 
            if (event.onPort("loc_state"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				LocalisationState_fromValue(&val, loc_state);
            }
            // 
            if (event.onPort("sideId"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				sideId = Long_fromValue(&val);
            }
            // 
            if (event.onPort("TYPE"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				TYPE = EntityType_fromValue(&val);
            }
            // 
            if (event.onPort("SUBTYPE"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				SUBTYPE = Long_fromValue(&val);
            }
            // 
            if (event.onPort("interactions"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				EnvironmentInteractions_fromValue(&val, interactions);
            }
            // 
            if (event.onPort("nav_state"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				NavigationState_fromValue(&val, nav_state);
            }
            // 
            if (event.onPort("mms_nav_update"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				NavigationUpdate_fromValue(&val, mms_nav_update);
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

DECLARE_DYNAMICS(generated::Flight)
