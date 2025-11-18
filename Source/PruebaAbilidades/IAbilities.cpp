// Fill out your copyright notice in the Description page of Project Settings.


#include "IAbilities.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UIAbilities::UIAbilities()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	AbilityName = "DefaultAbility";
	IsAbilityActive = true;
	// ...
}

//Activa el componente y que llame a tick
void UIAbilities::ActivateAbility()
{
	if (IsAbilityActive) return;
	IsAbilityActive = true;

	SetComponentTickEnabled(true);
	SetActive(true);

	//Implementacion especifica de la habilidad
	OnActivated();
}
//Desactiva el componente y que llame a tick
void UIAbilities::DesactivateAbility()
{
	if (!IsAbilityActive) return;
	IsAbilityActive = false;

	SetComponentTickEnabled(false);
	SetActive(false);

	//Implementacion especifica de la habilidad
	OnDeactivated();
}

//Destruye 1 componente de habilidad en el actor dado
void UIAbilities::DestroyAbilityOnActor(AActor* Actor)
{
	if (!Actor) return;
	
	if (UIAbilities* Comp = Actor->FindComponentByClass<UIAbilities>())
	{
		Comp->DestroyComponent( false);
	}
}

//Destruye la habilidad dada
void UIAbilities::DestroyAbilityComponent(UIAbilities* Ability)
{
	if (!Ability) return;
	Ability->DestroyComponent( false);
}
/* Obtiene una copia de la habilidad actual
 *	Se la añade al actor OtherActor
 *	Devuelve la nueva habilidad copiada
 */

UIAbilities* UIAbilities::CopyAbilityToActor(AActor* OtherActor, bool RegisterComponent)
{
	if (!OtherActor) {
		UE_LOG(LogTemp, Warning, TEXT("CopyAbilityToActor: OtherActor es NULL"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("CopyAbilityToActor: OtherActor es NULL"));
		}
		return nullptr;
	}
	UIAbilities* NewAbility = NewObject<UIAbilities>(OtherActor, this->GetClass());
	if (NewAbility)
	{
		NewAbility->AbilityName = this->AbilityName;
		NewAbility->IsAbilityActive = this->IsAbilityActive;
		NewAbility->OnComponentCreated();
		OtherActor->AddInstanceComponent(NewAbility);
		if (RegisterComponent)
		{
			NewAbility->RegisterComponent();
		}
		NewAbility->SetComponentTickEnabled(PrimaryComponentTick.bCanEverTick && IsAbilityActive);
	}
	return NewAbility;
}

void UIAbilities::OnActivated()
{
	// Implementación por defecto: nada. Subclases pueden override.
}

void UIAbilities::OnDeactivated()
{
	// Implementación por defecto: nada. Subclases pueden override.
}

// Called when the game starts
void UIAbilities::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UIAbilities::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

