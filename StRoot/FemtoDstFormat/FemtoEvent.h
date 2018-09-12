#ifndef FEMTO_EVENT_H
#define FEMTO_EVENT_H

#include "FemtoDstBranch.h"

class FemtoEvent : public FemtoDstBranch
{
public:
	virtual const char* classname() const { return "FemtoEvent"; } 
	FemtoEvent() {
		mPrimaryVertex_mX1 = 0;
		mPrimaryVertex_mX2 = 0;
		mPrimaryVertex_mX3 = 0;
		mVpdVz             = 0;
		mRunId             = 0;
		mEventId           = 0;
		mRanking           = 0;
		mGRefMult          = 0;
		mRefMult           = 0;
		mRunIndex          = 0;
		mNBTofMatched      = 0;
		mNBTofHits         = 0;
		mNTracks           = 0;
		mNVerts            = 0;
		mNVpdEast          = 0;
		mNVpdWest          = 0;
	}
	~FemtoEvent() {}

	void copy( FemtoEvent * that ){
		this->mPrimaryVertex_mX1 = that->mPrimaryVertex_mX1;
		this->mPrimaryVertex_mX2 = that->mPrimaryVertex_mX2;
		this->mPrimaryVertex_mX3 = that->mPrimaryVertex_mX3;
		this->mVpdVz             = that->mVpdVz;
		this->mRunId             = that->mRunId;
		this->mEventId           = that->mEventId;
		this->mGRefMult          = that->mGRefMult;
		this->mRefMult           = that->mRefMult;
		this->mRunIndex          = that->mRunIndex;
		this->mNBTofMatched 	 = that->mNBTofMatched;
		this->mNBTofHits 	     = that->mNBTofHits;
		this->mNTracks 		     = that->mNTracks;
		this->mNVerts 		     = that->mNVerts;
		this->mRanking 		     = that->mRanking;
		this->mNVpdEast 		 = that->mNVpdEast;
		this->mNVpdWest 		 = that->mNVpdWest;
	}

	int year() const { return (mRunId / 1000000) - 1 + 2000; }
	
	void vertex( Float_t x, Float_t y, Float_t z ){
		this->mPrimaryVertex_mX1 = x;
		this->mPrimaryVertex_mX2 = y;
		this->mPrimaryVertex_mX3 = z;
	}

	template <typename T>
	T v( string name ){
		if ( name == "mPrimaryVertex_mX1" ) return mPrimaryVertex_mX1;
		if ( name == "mPrimaryVertex_mX2" ) return mPrimaryVertex_mX2;
		if ( name == "mPrimaryVertex_mX3" ) return mPrimaryVertex_mX3;
		if ( name == "mRunId" ) return mRunId;
		if ( name == "mEventId" ) return mEventId;
		if ( name == "mGRefMult" ) return mGRefMult;
		if ( name == "mRefMult" ) return mRefMult;
		if ( name == "mRunIndex" ) return mRunIndex;
		return 0;
	}


	Float_t 	mPrimaryVertex_mX1;		// Event VertexX
	Float_t 	mPrimaryVertex_mX2;		// Event VertexY
	Float_t 	mPrimaryVertex_mX3;		// Event VertexZ
	Float_t 	mVpdVz;	             	// Event VertexZ from VPD
	Int_t 		mRunId;					// Run ID
	Int_t 		mEventId;				// Event Id
	UShort_t 	mGRefMult;				// global RefMult
	UShort_t 	mRefMult;				// RefMult
	UShort_t 	mNBTofMatched;			// nBTof Matched Tracks
	UShort_t 	mNBTofHits;				// nBTof Hits
	UShort_t 	mNTracks;				// n Tracks
	UShort_t 	mNVerts;				// n Verts
	Float_t 	mRanking;				// vertex Ranking
	UShort_t 	mNVpdEast;				// n Vpd East
	UShort_t 	mNVpdWest;				// n Vpd West
	UShort_t 	mRunIndex;				// the run index

	ClassDef( FemtoEvent, 4 )
};


#endif