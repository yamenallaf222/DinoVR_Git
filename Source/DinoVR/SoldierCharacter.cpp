// Fill out your copyright notice in the Description page of Project Settings.


#include "SoldierCharacter.h"
#include "Guns/BaseWeapon.h"

ASoldierCharacter::ASoldierCharacter()
{

}
void ASoldierCharacter::BeginPlay()
{

	Super::BeginPlay();
	ABaseWeapon* FirstWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponBPClass);

	USkeletalMeshComponent* CharacterMesh = GetMesh();

	if (!ensure(FirstWeapon != nullptr))return;

	if (!ensure(CharacterMesh != nullptr))return;

	Weapons.Add(FirstWeapon);

	FirstWeapon->SetOwner(this);

	FirstWeapon->AttachToComponent(CharacterMesh, FAttachmentTransformRules::KeepRelativeTransform, "Weapon_rSocket");

	EquippedWeaponIndex = Weapons.IndexOfByKey(FirstWeapon);


}

void ASoldierCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	
}

void ASoldierCharacter::Attack()
{
	if (!EquippedWeaponIndex.IsSet()) return;

	if (!ensure(Weapons[EquippedWeaponIndex.GetValue()] != nullptr))return;

	Weapons[EquippedWeaponIndex.GetValue()]->PullTrigger();

}


