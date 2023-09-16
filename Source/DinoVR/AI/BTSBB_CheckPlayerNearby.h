// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTSBB_CheckPlayerNearby.generated.h"

/**
 * 
 */
UCLASS()
class DINOVR_API UBTSBB_CheckPlayerNearby : public UBTService_BlackboardBase
{
	GENERATED_BODY()


public:
	UBTSBB_CheckPlayerNearby();
protected:
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


private:

	bool IsPlayerNearby(UBehaviorTreeComponent& OwnerComp);

};
