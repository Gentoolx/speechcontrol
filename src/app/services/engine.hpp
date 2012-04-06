/***
 *  This file is part of SpeechControl.
 *
 *  Copyright (C) 2012 Jacky Alciné <jackyalcine@gmail.com>
 *
 *  SpeechControl is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  SpeechControl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with SpeechControl.  If not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef SERVICES_ENGINE_HPP
#define SERVICES_ENGINE_HPP

#include <QMap>
#include <QList>
#include <QObject>
#include <QString>
#include <macros.hpp>

class QPixmap;

namespace SpeechControl
{
namespace Services
{
class AbstractModule;
class Engine;

/**
 * @brief Represents a list of Modules.
 **/
typedef QList<AbstractModule*> ModuleList;

/**
 * @brief Represents  a service module.
 *
 * Modules serve as wrappers to the interfaces that internal and external components
 * of SpeechControl can provide.
 **/
class AbstractModule : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY (AbstractModule)

signals:
    /**
     * @brief Emitted when this AbstractModule's started.
     **/
    void started();

    /**
     * @brief Emitted when this AbstractModule's stopped.
     **/
    void stopped();

public:
    /**
     * @brief Obtains the friendly name of this AbstractModule.
     **/
    virtual QString name() const = 0;

    /**
     * @brief Obtains the ID of the AbstractModule.
     **/
    virtual QString id() const = 0;

    /**
     * @brief Obtains the QPixmap to use with this AbstractModule.
     **/
    virtual QPixmap pixmap() const = 0;

    /**
     * @brief Determines if this AbstractModule is enabled.
     **/
    virtual bool isEnabled() const = 0;

    /**
     * @brief Determines if this AbstractModule is active.
     **/
    virtual bool isActive() const = 0;

public slots:
    /**
     * @brief Starts this AbstractModule.
     **/
    void start();

    /**
     * @brief Stops this AbstractModule.
     **/
    void stop();

protected:
    virtual void initialize() = 0;
    virtual void deinitialize() = 0;
    AbstractModule (QObject* p_parent);
};

/**
 * @brief Represents the core Service engine.
 *
 * Engine holds the integral part of dispatching the addition and removal of
 * modules in SpeechControl.
 **/
class Engine : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY (Engine)
    SC_SINGLETON (Engine)
    friend class AbstractModule;

signals:
    /**
     * @brief Emitted when the Engine's started.
     **/
    void started();

    /**
     * @brief Emitted when the Engine's stopped.
     **/
    void stopped();

public:
    /**
     * @brief Searches for a AbstractModule.
     *
     * @param p_id The ID of the AbstractModule in question.
     * @return A pointer to a AbstractModule if found, NULL otherwise.
     **/
    static AbstractModule* findModule (const QString& p_id);

    /**
     * @brief Obtains all of the AbstractModules registered.
     *
     * @return :Services::ModuleList
     **/
    static ModuleList allModules();

    /**
     * @brief Registers a AbstractModule.
     *
     * @param p_module The Module to add to the Engine.
     **/
    static void registerModule (AbstractModule* p_module);

    /**
     * @brief Unregisters a AbstractModule.
     *
     * @param p_module The Module to remove to the Engine.
     **/
    static void unregisterModule (AbstractModule* p_module);

public slots:
    /**
     * @brief Starts the Engine.
     **/
    static void start();

    /**
     * @brief Stops the Engine.
     **/
    static void stop();

private:
    static QMap<QString, AbstractModule*> s_list;
};

}
}


#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
