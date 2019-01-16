/*  
 *  Version: MPL 1.1
 *  
 *  The contents of this file are subject to the Mozilla Public License Version 
 *  1.1 (the "License"); you may not use this file except in compliance with 
 *  the License. You may obtain a copy of the License at 
 *  http://www.mozilla.org/MPL/
 *  
 *  Software distributed under the License is distributed on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 *  for the specific language governing rights and limitations under the
 *  License.
 *  
 *  The Original Code is the YSI 2.0 SA:MP plugin.
 *  
 *  The Initial Developer of the Original Code is Alex "Y_Less" Cole.
 *  Portions created by the Initial Developer are Copyright (C) 2008
 *  the Initial Developer. All Rights Reserved.
 *  
 *  Contributor(s):
 *  
 *  Peter Beverloo
 *  Marcus Bauer
 */
#pragma once
#include "Structs.h"

extern void
	*g_pCStream__Write;

class CStream
{
private:
	SS_CStream
		m_csPad;
public:
	CStream();
	~CStream();
	
	template <class T>
	inline void Write(T data)
	{
		const int
			ts = sizeof (T) * 8;
		_asm mov ecx, this
		_asm push 1
		_asm push ts
		_asm lea eax, data
		_asm push eax
		_asm mov eax, g_pCStream__Write
		_asm call eax
	};
	void Send(char *type, short playerid);
	SS_PlayerID GetPlayer(short playerid);
};
