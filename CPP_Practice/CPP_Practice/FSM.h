#pragma once
#include <memory>

class FSMState;

class FSM
{
public:
	FSM() = default;
	virtual ~FSM() = default;

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void ChangeState(std::unique_ptr<FSMState> nextState) = 0;
};

class FSMState
{
public:
	FSMState() = default;
	virtual ~FSMState() = default;

public:
	virtual void Enter() = 0;
	virtual void Execute() = 0;
	virtual void Exit() = 0;
	virtual std::unique_ptr<FSMState> GetNextState() = 0;

public:
	bool IsComplete() const { return isComplete; }

protected:
	bool isComplete{};
};