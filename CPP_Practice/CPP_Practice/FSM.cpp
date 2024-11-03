#include "FSM.h"
#include <iostream>

using namespace std;

class ClearingTableState : public FSMState
{
public:
	ClearingTableState() = default;
	virtual ~ClearingTableState() = default;

public:
	void Enter() override
	{
		cout << "Enter clearing table" << endl;
		isComplete = false;
	}

	void Execute() override
	{
		cout << "Clearing table" << endl;
		isComplete = true;
	}

	void Exit() override
	{
		cout << "Exiting clearing table" << endl;
	}

	unique_ptr<FSMState> GetNextState() override
	{
		return nullptr;
	}
};

class EatingState : public FSMState
{
public:
	EatingState() = default;
	virtual ~EatingState() = default;

public:
	void Enter() override
	{
		cout << "Enter eating food" << endl;
		isComplete = false;
	}

	void Execute() override
	{
		cout << "Eating food" << endl;
		isComplete = true;
	}

	void Exit() override
	{
		cout << "Exiting eating food" << endl;
	}

	unique_ptr<FSMState> GetNextState() override
	{
		return make_unique<ClearingTableState>();
	}
};

class SettingTableState : public FSMState
{
public:
	SettingTableState() = default;
	virtual ~SettingTableState() = default;

public:
	void Enter() override
	{
		cout << "Enter setting table" << endl;
		isComplete = false;
	}

	void Execute() override
	{
		cout << "Setting table" << endl;
		isComplete = true;
	}

	void Exit() override
	{
		cout << "Exiting setting table" << endl;
	}

	unique_ptr<FSMState> GetNextState() override
	{
		return make_unique<EatingState>();
	}
};

class CookingRiceState : public FSMState
{
public:
	CookingRiceState() = default;
	virtual ~CookingRiceState() = default;

public:
	void Enter() override
	{
		cout << "Enter cooking rice" << endl;
		isComplete = false;
	}

	void Execute() override
	{
		cout << "Cooking rice" << endl;
		isComplete = true;
	}

	void Exit() override
	{
		cout << "Exiting cooking rice" << endl;
	}

	unique_ptr<FSMState> GetNextState() override
	{
		return make_unique<SettingTableState>();
	}
};

class EatingFSM : public FSM
{
public:
	void Start() override
	{
		ChangeState(make_unique<CookingRiceState>());
	}

	void Update() override
	{
		if (state == nullptr)
		{
			return;
		}
		state->Execute();

		if (not state->IsComplete())
		{
			return;
		}
		
		auto nextState = state->GetNextState();
		if (nextState != nullptr)
		{
			ChangeState(move(nextState));
		}
		else
		{
			cout << "All task completed" << endl;
			state.reset();
		}
	}

	void ChangeState(unique_ptr<FSMState> nextState) override
	{
		if (state != nullptr)
		{
			state->Exit();
			state.reset();
		}

		state = move(nextState);
		if (state != nullptr)
		{
			state->Enter();
		}
	}

	bool IsFSMAllTaskCompleted() const
	{
		return state == nullptr;
	}

private:
	unique_ptr<FSMState> state{};
};

int main()
{
	EatingFSM testFSM;
	testFSM.Start();
	bool isFSMRunning{true};

	while (isFSMRunning)
	{
		testFSM.Update();
		isFSMRunning = (!testFSM.IsFSMAllTaskCompleted());
	}

	return 0;
}