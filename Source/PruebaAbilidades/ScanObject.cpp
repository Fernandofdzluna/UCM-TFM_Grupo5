// Fill out your copyright notice in the Description page of Project Settings.


#include "ScanObject.h"

// Sets default values for this component's properties
UScanObject::UScanObject()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SaveObjectMap = TMap<int, AScanableObject*>();

	// ...
}

//Scanea el objeto que tenga delante y lo guarda en un mapa con un indice unico
bool UScanObject::ScanObject(AScanableObject* ActorToScan) {

	if (!IsValid(ActorToScan)) return false;

	/*detecta si el objeto ya ha sido escaneado por la key(index)
	 * Ahora mismo no funciona bien porque el index de los objetos que no se han escaneado es el mismo, 0
	 * A no ser que lo cambie en el blueprint al crear el objeto
	 */

	if (SaveObjectMap.Contains(ActorToScan->GetIndex())) {
		UE_LOG(LogTemp, Warning, TEXT("El actor ya esta copiado"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("El actor ya esta copiado"));
		}
		return false;
	}


	int aux = SaveObjectMap.Num();
	ActorToScan->SetIndex(aux);
	SaveObjectMap.Add(aux, ActorToScan);

	return true; 
}

//genera una copia del objeto escaneado si este esta en el mapa
AScanableObject* UScanObject::SpawnObject(AScanableObject* ActorToGet)
{
	if (!IsValid(ActorToGet)) return nullptr; 
	UWorld* World = GetWorld(); 
	if (!World) return nullptr; 

	if (SaveObjectMap.Find(ActorToGet->GetIndex()))
	{
		FTransform SpawnTransform = GetOwner()->GetActorTransform(); 
		SpawnTransform.SetLocation(SpawnTransform.GetLocation() + GetOwner()->GetActorForwardVector() * Spawndistance); 
		AScanableObject* SpawnedActor = World->SpawnActor<AScanableObject>(ActorToGet->GetClass(), SpawnTransform);
		if (!IsValid(SpawnedActor)) return nullptr; 

		return SpawnedActor;
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

