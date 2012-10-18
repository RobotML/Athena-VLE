#include <vle/value.hpp>
#include <vle/devs.hpp>
#include <TypeDefs.h>
#include <TypeDefs_Values.h>

namespace vd = vle::devs;
namespace vv = vle::value;

namespace generated {

class MMSUpdate : public vd::Dynamics
{
private:

	// references ----------------------------------------------------------------------------------------------
		
	Long time;
	Long timestep;
	Long cycle;
	Long NID;

	// parameters ----------------------------------------------------------------------------------------------

	Logical bfalse;		
	Logical btrue;		

public:

	/**
	 *
	 */
    MMSUpdate(const vd::DynamicsInit& init, const vd::InitEventList& events)
        : vd::Dynamics(init, events)
    {
    }

	/**
	 *
	 */
    virtual ~MMSUpdate()
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

DECLARE_DYNAMICS(generated::MMSUpdate)
