/*------------------------------------------------------------------------
* (The MIT License)
* 
* Copyright (c) 2008-2011 Rhomobile, Inc.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
* 
* http://rhomobile.com
*------------------------------------------------------------------------*/

#include "RhoConvertWP8.h"
#include "common/StringConverter.h"
#include <collection.h>

using namespace Windows::Foundation::Collections;

namespace rho
{

extern "C" {

::Platform::String^ convertStringWP8(const rho::String& str)
{
    rho::StringW strW = rho::common::convertToStringW(str);
    return ref new ::Platform::String(strW.c_str());
}

IVectorView<Platform::String^>^ convertArrayWP8(const rho::Vector<rho::String>& arr)
{
	// TODO: convert string array
	return ref new Platform::Collections::VectorView<Platform::String^>();
}

IMapView<Platform::String^, Platform::String^>^ convertHashWP8(const rho::Hashtable<rho::String, rho::String>& hash)
{
	// TODO: convert string hash
	return ref new Platform::Collections::MapView<Platform::String^, Platform::String^>();
}

}

}