/**
 * \file doormodule.hpp
 * \author Thibault Schueller <ryp.sqrt@gmail.com>
 * \brief door module class
 */

#ifndef DOORMODULE_HPP
#define DOORMODULE_HPP

#include "modules/imodule.hpp"

class DoorModule : public IModule
{
public:
    explicit DoorModule(ICore& core, const std::string& name);
    ~DoorModule() noexcept = default;

    DoorModule(const DoorModule& other) = delete;
    DoorModule& operator=(const DoorModule& other) = delete;

public:
    virtual void                notify(const Event& event) override;
    virtual const std::string&  getName() const override;
    virtual ModuleType          getType() const override;
    virtual void                serialize(boost::property_tree::ptree& node) override;
    virtual void                deserialize(boost::property_tree::ptree& node) override;

private:
    IEventListener&     _listener;
    const std::string   _name;
};

#endif // DOORMODULE_HPP
