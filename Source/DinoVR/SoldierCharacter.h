// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DinoVRCharacter.h"
#include "SoldierCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DINOVR_API ASoldierCharacter : public ADinoVRCharacter
{
	GENERATED_BODY()


public:

	void Attack() override;

	ASoldierCharacter();
	void Tick(float DeltaSeconds)override;

protected:

	void BeginPlay() override;
private:

	TSubclassOf<UAnimInstance> AnimClass;

	TOptional<int32> EquippedWeaponIndex;


	UPROPERTY(VisibleAnywhere)
	TArray<class ABaseWeapon*> Weapons;


	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABaseWeapon> WeaponBPClass;
	

	
};
