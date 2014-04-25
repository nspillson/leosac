/**
 * \file imodule.hpp
 * \author Thibault Schueller <ryp.sqrt@gmail.com>
 * \brief module class interface
 */

#ifndef IMODULE_HPP
#define IMODULE_HPP

#include <string>

class IModule
{
public:
    typedef IModule* (*InitFunc)();
    enum Type {
        Door,
        AccessPoint,
        Auth,
        Logger,
        ActivityMonitor
    };

public:
    virtual ~IModule() {}
    virtual Type                getType() const = 0;
    virtual const std::string&  getVersionString() const = 0;
};

#endif // IMODULE_HPP