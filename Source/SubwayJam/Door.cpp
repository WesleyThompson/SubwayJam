// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"
#include "../../Plugins/Wwise/Source/AkAudio/Classes/BlueprintNodes/PostEventAsync.h"
#include "../../Plugins/Wwise/ThirdParty/include/AK/SoundEngine/Common/AkSoundEngine.h"
#include "BlueprintNodes/PostEventAsync.h"

// Sets default values for this component's properties
UDoor::UDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MoveTime = FMath::Clamp(MoveTime, 0.f, FLT_MAX);
}


// Called when the game starts
void UDoor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = DoorMesh->GetRelativeLocation();
	TargetLocation = StartLocation;
	OpenLocation = StartLocation + OpenOffset;
	
	if(MoveTime != 0)
	{
		MoveSpeed = FVector::Distance(OpenLocation, StartLocation) / MoveTime;
	}

	OnInteractDelegate.AddUniqueDynamic(this, &UDoor::OpenDoor);
}


// Called every frame
void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(ShouldMove && !Locked)
	{
		if(MoveTime == 0)
		{
			DoorMesh->SetRelativeLocation(TargetLocation);
			ShouldMove = false;
		}
		else
		{
			FVector newLocation = FMath::VInterpConstantTo(DoorMesh->GetRelativeLocation(), TargetLocation, DeltaTime, MoveSpeed);
			DoorMesh->SetRelativeLocation(newLocation);
		}
	}
}

void UDoor::OpenDoor()
{
	UE_LOG(LogTemp, Display, TEXT("Opening Door"));
	if(!Locked)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), OpenSound, GetOwner()->GetActorLocation());
	}

	TargetLocation = OpenLocation;
	ShouldMove = true;

	if(AutoClose)
	{
		GetWorld()->GetTimerManager().SetTimer(CloseTimerHandle, this, &UDoor::CloseDoor, CloseDelay, false);
	}
}

void UDoor::CloseDoor()
{
	if(!Locked)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), CloseSound, GetOwner()->GetActorLocation());
	}

	TargetLocation = StartLocation;
	ShouldMove = true;
}

void UDoor::DoorStateCheck()
{
	if(DoorMesh->GetRelativeLocation().Equals(OpenLocation))
	{
		isOpen = true;
	}
	else
	{
		isOpen = false;
	}

	if(DoorMesh->GetRelativeLocation().Equals(OpenLocation) && TargetLocation.Equals(OpenLocation) ||
		DoorMesh->GetRelativeLocation().Equals(StartLocation) && TargetLocation.Equals(StartLocation))
	{
		ShouldMove = false;
	}
}

