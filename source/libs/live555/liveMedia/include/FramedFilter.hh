/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**********/
// "liveMedia"
// Copyright (c) 1996-2008 Live Networks, Inc.  All rights reserved.
// Framed Filters
// C++ header

#ifndef _FRAMED_FILTER_HH
#define _FRAMED_FILTER_HH

#ifndef _FRAMED_SOURCE_HH
#include "FramedSource.hh"
#endif

class FramedFilter: public FramedSource {
public:
  FramedSource* inputSource() const { return fInputSource; }

protected:
  FramedFilter(UsageEnvironment& env, FramedSource* inputSource);
	 // abstract base class
  virtual ~FramedFilter();

protected:
  // Redefined virtual functions (with default 'null' implementations):
  virtual char const* MIMEtype() const;
  virtual void getAttributes() const;
  virtual void doStopGettingFrames();

protected:
  FramedSource* fInputSource;
};

#endif
