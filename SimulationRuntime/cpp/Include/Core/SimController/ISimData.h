#pragma once
#include <Core/DataExchange/ISimVar.h>

#ifdef ANALYZATION_MODE
#include <string.h>
#include <boost/numeric/ublas/fwd.hpp>
#endif

namespace uBlas = boost::numeric::ublas;

class ISimData
{
public:
	virtual ~ISimData() {};

	virtual void Add(std::string key,boost::shared_ptr<ISimVar> var) = 0;
	//Returns SimVar for a key
	virtual ISimVar* Get(std::string key) = 0;
	//Adds Results for an output var to simdata object
	virtual void addOutputResults(std::string name,uBlas::vector<double> v) = 0;
	//Returns reference to results for an output var, when simData object is destroyed results are no longer valid
	virtual void getOutputResults(std::string name,uBlas::vector<double>& v) = 0;
	//Clears all output var results
	virtual void clearResults() = 0;
	//Return the time intervall
	virtual void getTimeEntries(std::vector<double>& time_entries) = 0;
	virtual void addTimeEntries(std::vector<double> time_entries) = 0;
};
