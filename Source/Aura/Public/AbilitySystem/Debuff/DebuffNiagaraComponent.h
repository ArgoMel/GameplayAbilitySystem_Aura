// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "GameplayTagContainer.h"
#include "DebuffNiagaraComponent.generated.h"

UCLASS()
class AURA_API UDebuffNiagaraComponent : public UNiagaraComponent
{
	GENERATED_BODY()
public:
	UDebuffNiagaraComponent();
protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(VisibleAnywhere)
	FGameplayTag DebuffTag;

protected:
	void DebuffTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
};
