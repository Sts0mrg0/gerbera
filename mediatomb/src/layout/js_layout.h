/*MT*
    
    MediaTomb - http://www.mediatomb.cc/
    
    js_layout.h - this file is part of MediaTomb.
    
    Copyright (C) 2005 Gena Batyan <bgeradz@mediatomb.cc>,
                       Sergey 'Jin' Bostandzhyan <jin@mediatomb.cc>
    
    Copyright (C) 2006-2007 Gena Batyan <bgeradz@mediatomb.cc>,
                            Sergey 'Jin' Bostandzhyan <jin@mediatomb.cc>,
                            Leonhard Wimmer <leo@mediatomb.cc>
    
    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2
    as published by the Free Software Foundation.
    
    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    version 2 along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
    
    $Id$
*/

/// \file js_layout.h

#ifndef __JS_SCRIPTING_H__
#define __JS_SCRIPTING_H__

#ifdef __APPLE__
    #define XP_MAC 1
#else
    #define XP_UNIX 1
#endif

#include <jsapi.h>
#include "layout.h"

class JSLayout : public Layout
{
protected:
    JSVersion version;
    JSRuntime *rt;
    JSContext *cx;
    JSObject  *glob;
	JSScript *script;

public:
	JSLayout();
	virtual ~JSLayout();
	virtual void init();
	virtual void processCdsObject(zmm::Ref<CdsObject> obj);	
};

#endif // __JS_SCRIPTING_H__
