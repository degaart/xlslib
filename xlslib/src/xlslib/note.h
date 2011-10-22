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
#ifndef NOTE_H
#define NOTE_H

#include <xlsys.h>
#include <common.h>

#include <cell.h>
#include <record.h>
#include <unit.h>


// #include <xls_pshpack2.h>

namespace xlslib_core
{

  class note_t: public cell_t
    {
	  friend class worksheet;

    private:
		note_t(CGlobalRecords& gRecords, unsigned32_t rowval, unsigned32_t colval, const std::string& text, const std::string& author, xf_t* pxfval = NULL);
		note_t(CGlobalRecords& gRecords, unsigned32_t rowval, unsigned32_t colval, const std::ustring& text, const std::ustring& author, xf_t* pxfval = NULL);
		note_t(CGlobalRecords& gRecords, unsigned32_t rowval, unsigned32_t colval, const u16string& text, const u16string& author, xf_t* pxfval = NULL);
	  virtual ~note_t();
	  
    public:
      virtual size_t GetSize(void) const;
      virtual CUnit* GetData(CDataStorage &datastore) const;

	private:
		u16string text;
		u16string author;

	public:
		const u16string& GetNote(void) const {return text;};
		const u16string& GetAuthor(void) const {return author;};
    };


  // forward ref
	class CDataStorage;

  class CNote: public CRecord
    {
#if defined(LEIGHTWEIGHT_UNIT_FEATURE)
	friend class CDataStorage;
#endif

    protected:
      CNote(CDataStorage &datastore, const note_t& notedef);

	  void mk_obj_Record(const note_t* notedef);
	  void mk_obj_CMO_SubRecord(const note_t* notedef);
	  void mk_obj_END_SubRecord(const note_t* notedef);
	  void mk_obj_NTS_SubRecord(const note_t* notedef);

	private:
      virtual ~CNote();
    };

}


// #include <xls_poppack.h>

#endif

