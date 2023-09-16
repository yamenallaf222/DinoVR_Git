// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTSBB_GetPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class DINOVR_API UBTSBB_GetPlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTSBB_GetPlayerLocation();



protected:
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
