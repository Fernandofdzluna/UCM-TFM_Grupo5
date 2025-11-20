// Fill out your copyright notice in the Description page of Project Settings.


#include "ScanObject.h"

// Sets default values for this component's properties
UScanObject::UScanObject()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SaveObject = TArray<AScanableObject*>();

	// ...
}

//Scanea el objeto que tenga delante y lo guarda en un mapa con un indice unico
bool UScanObject::ScanObject(AScanableObject* ActorToScan) {

	if (!IsValid(ActorToScan)) return false;
	
	//Destecta si el actor ya ha sido escaneado
	for (int i = 0; i < SaveObject.Num(); i++)
	{
		if (SaveObject[i]->GetClass() == ActorToScan->GetClass()) return false;
	}
	
	SaveObject.Add(ActorToScan);
	return true; 
}

//genera una copia del objeto escaneado si este esta en el mapa
AScanableObject* UScanObject::SpawnObject(AScanableObject* ActorToGet)
{
	if (!IsValid(ActorToGet)) return nullptr; 
	UWorld* World = GetWorld(); 
	if (!World) return nullptr; 
	for (int i = 0; i < SaveObject.Num(); i++)
	{
		if (SaveObject[i]->GetClass() == ActorToGet->GetClass())
		{
			FTransform SpawnTransform = GetOwner()->GetActorTransform(); 
			SpawnTransform.SetLocation(SpawnTransform.GetLocation() + GetOwner()->GetActorForwardVector() * Spawndistance); 
			AScanableObject* SpawnedActor = World->SpawnActor<AScanableObject>(ActorToGet->GetClass(), SpawnTransform);
			if (!IsValid(SpawnedActor)) return nullptr; 

			return SpawnedActor;
		}
	}
	return nullptr;
}

// Called when the game starts
void UScanObject::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UScanObject::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

