// Copyright Druid Mechanics

#include "AI/BTTask_Attack.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AIController.h"
#include "AuraGameplayTags.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interaction/EnemyInterface.h"

UBTTask_Attack::UBTTask_Attack()
{
	NodeName=TEXT("Attack");
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (CombatTargetSelector.IsNone())
	{
		FinishLatentTask(OwnerComp,EBTNodeResult::Failed);
		return EBTNodeResult::Failed;
	}
	
	APawn* controlledPawn= OwnerComp.GetAIOwner()->GetPawn();
	if (!controlledPawn->Implements<UEnemyInterface>())
	{
		FinishLatentTask(OwnerComp,EBTNodeResult::Failed);
		return EBTNodeResult::Failed;
	}
	
	const UBlackboardComponent* BB=OwnerComp.GetBlackboardComponent();
	AActor* target=Cast<AActor>(BB->GetValueAsObject(CombatTargetSelector.SelectedKeyName));
	IEnemyInterface::Execute_SetCombatTarget(controlledPawn,target);
	UAbilitySystemComponent* ASC= UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(controlledPawn);
	check(ASC);
	FGameplayTagContainer TagContainer;
	TagContainer.AddTag(FAuraGameplayTags::Get().Abilities_Attack);
	ASC->TryActivateAbilitiesByTag(TagContainer);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
