// Copyright Druid Mechanics

#include "AI/BTService_FindNearestPlayer.h"
#include "AIController.h"
#include "Aura/Aura.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Float.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Kismet/GameplayStatics.h"

UBTService_FindNearestPlayer::UBTService_FindNearestPlayer()
{
	NodeName="FindNearestPlayer";
}

void UBTService_FindNearestPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	AAIController* AIController = OwnerComp.GetAIOwner();
	const APawn* OwningPawn = AIController->GetPawn();
	if (!IsValidChecked(OwningPawn))
	{
		return;
	}
	
	const FName TargetTag = OwningPawn->ActorHasTag(Aura_Tag::Player) ? Aura_Tag::Enemy : Aura_Tag::Player;

	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(OwningPawn, TargetTag, ActorsWithTag);

	float ClosestDistance = TNumericLimits<float>::Max();
	AActor* ClosestActor = nullptr;
	for (AActor* Actor : ActorsWithTag)
	{
		if (IsValid(Actor))
		{
			const float Distance = OwningPawn->GetDistanceTo(Actor);
			if (Distance < ClosestDistance)
			{
				ClosestDistance = Distance;
				ClosestActor = Actor;
			}
		}
	}
	if (UBlackboardComponent* BB = AIController->GetBlackboardComponent())
	{
		BB->SetValue<UBlackboardKeyType_Object>(TargetToFollowSelector.SelectedKeyName, ClosestActor);
		BB->SetValue<UBlackboardKeyType_Float>(DistanceToTargetSelector.SelectedKeyName, ClosestDistance);
	}
}
