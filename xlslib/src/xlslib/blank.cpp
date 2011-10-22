/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This file is part of xlslib -- A multiplatform, C/C++ library
 * for dynamic generation of Excel(TM) files.
 *
 * Copyright 2004 Yeico S. A. de C. V. All Rights Reserved.
 * Copyright 2008 David Hoerl All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 * 
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 * 
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY David Hoerl ''AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL David Hoerl OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * File description:
 *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <xlsys.h>

#include <blank.h>
#include <datast.h>


using namespace std;
using namespace xlslib_core;

/*
*********************************
blank_t class implementation
*********************************
*/
blank_t::blank_t(CGlobalRecords& gRecords, unsigned32_t rowval, unsigned32_t colval, xf_t* pxfval) :
	cell_t(gRecords, rowval, colval, pxfval)
{
}
CUnit* blank_t::GetData(CDataStorage &datastore) const {
#if defined(LEIGHTWEIGHT_UNIT_FEATURE)
   return datastore.MakeCBlank(*this);	// NOTE: this pointer HAS to be deleted elsewhere.
#else
   return (CUnit*)(new CBlank(datastore, *this));	// NOTE: this pointer HAS to be deleted elsewhere.
#endif
}
blank_t::~blank_t()
{
}

/*
*********************************
CBlank class implementation
*********************************
*/
CBlank::CBlank(CDataStorage &datastore, const blank_t& blankdef):
		CRecord(datastore)
{
   SetRecordType(RECTYPE_BLANK);
   AddValue16((unsigned16_t)blankdef.GetRow());
   AddValue16((unsigned16_t)blankdef.GetCol());
   AddValue16(blankdef.GetXFIndex());

   SetRecordLength(GetDataSize()-4);
}

CBlank::~CBlank()
{
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * $Log: blank.cpp,v $
 * Revision 1.4  2009/03/02 04:08:43  dhoerl
 * Code is now compliant to gcc  -Weffc++
 *
 * Revision 1.3  2009/01/08 02:53:15  dhoerl
 * December Rework
 *
 * Revision 1.2  2008/10/25 18:39:53  dhoerl
 * 2008
 *
 * Revision 1.1.1.1  2004/08/27 16:31:54  darioglz
 * Initial Import.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

