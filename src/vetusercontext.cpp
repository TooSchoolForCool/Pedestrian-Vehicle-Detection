#include "vetusercontext.h"

using namespace std;
using namespace cv;

VetUserContext::VetUserContext(UserMode user_mode)
{
	ptr_user_strategy_ = NULL;

	switch(user_mode)
	{
		case TEST_MODE:
			cout << "[VetUserContext::VetUserContext]: Create VetTestMode" << endl;
			ptr_user_strategy_ = new VetTestMode();
			break;
		case EVALUATE_MODE:
			cout << "[VetUserContext::VetUserContext]: Create VetEvaluator" << endl;
			ptr_user_strategy_ = new VetEvaluator();
			break;
		default:
			cout << "[VetUserContext::VetUserContext]: No Such Option" << endl;
			break;
	}
}

VetUserContext::~VetUserContext()
{
	delete ptr_user_strategy_;
}

void VetUserContext::start(string path)
{
	if(ptr_user_strategy_ == NULL)
	{
		error("Cannot start yet, ptr_user_strategy_ is NULL");
	}

	ptr_user_strategy_->start(path);
}