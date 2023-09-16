// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeHitBox.h"
#include "Components/BoxComponent.h"
#include "DinoVR/DinoVRCharacter.h"
// Sets default values
AMeleeHitBox::AMeleeHitBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	SetRootComponent(Root);

	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));

	HitBox->SetupAttachment(Root);


	HitBox->OnComponentBeginOverlap.AddDynamic(this, &AMeleeHitBox::OnBeginOverlap);
}

void AMeleeHitBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{



	if (OtherActor && Cast<ADinoVRCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor hit with dinosaur's hand : %s"), *OtherActor->GetClass()->GetName());
		Destroy();
	}
}

// Called when the game starts or when spawned
void AMeleeHitBox::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AMeleeHitBox::DestroySelfAtTimerEnd, 0.5f, 0);
}

void AMeleeHitBox::DestroySelfAtTimerEnd()
{
	Destroy();
}

// Called every frame
void AMeleeHitBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

