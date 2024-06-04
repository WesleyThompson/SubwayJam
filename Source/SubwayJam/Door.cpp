// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

// Sets default values for this component's properties
UDoor::UDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UDoor::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentPosition = GetOwner()->GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("%s"), *CurrentPosition.ToCompactString());
}


// Called every frame
void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
}

void UDoor::OpenDoor()
{
	if(!Locked)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), OpenSound, GetOwner()->GetActorLocation());
	}
}

void UDoor::CloseDoor()
{
	if(!Locked)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), CloseSound, GetOwner()->GetActorLocation());
	}
}

