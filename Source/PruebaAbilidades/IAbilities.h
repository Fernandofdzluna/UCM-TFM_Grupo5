// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IAbilities.generated.h"


UCLASS(Blueprintable,BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRUEBAABILIDADES_API UIAbilities : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIAbilities();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FString AbilityName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	bool IsAbilityActive;
	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual UIAbilities* CopyAbilityToActor(AActor* OtherActor, bool RegisterComponent);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual void ActivateAbility();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual void DesactivateAbility();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	static void DestroyAbilityOnActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	static void DestroyAbilityComponent(UIAbilities* Ability);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void OnActivated();
	virtual void OnDeactivated();
	;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
