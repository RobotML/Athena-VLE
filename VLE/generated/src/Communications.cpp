#include <vle/value.hpp>
#include <vle/devs.hpp>
#include <TypeDefs.h>
#include <TypeDefs_Values.h>

namespace vd = vle::devs;
namespace vv = vle::value;

namespace generated {

class Communications : public vd::Dynamics
{
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

public:

	/**
	 *
	 */
    Communications(const vd::DynamicsInit& init, const vd::InitEventList& events)
        : vd::Dynamics(init, events)
    {
    }

	/**
	 *
	 */
    virtual ~Communications()
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
            if (event.onPort("networksPtr"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				networksPtr = Pointer_fromValue(&val);
            }
            // 
            if (event.onPort("nav_msgCategoryId"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				nav_msgCategoryId = Long_fromValue(&val);
            }
            // 
            if (event.onPort("nav_toBeSent"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				nav_toBeSent = NetworkMessageList_fromValue(&val);
            }
            // 
            if (event.onPort("nav_received"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				nav_received = NetworkMessageList_fromValue(&val);
            }
            // 
            if (event.onPort("mms_msgCategoryId"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				mms_msgCategoryId = Long_fromValue(&val);
            }
            // 
            if (event.onPort("mms_toBeSent"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				mms_toBeSent = NetworkMessageList_fromValue(&val);
            }
            // 
            if (event.onPort("mms_received"))
            {
			    const vv::Value& val = event.getAttributeValue("hello");
				mms_received = NetworkMessageList_fromValue(&val);
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

DECLARE_DYNAMICS(generated::Communications)
