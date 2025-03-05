// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "AuraGameplayTags.h"
#include "Engine/DataAsset.h"
#include "AttributeInfo.generated.h"

UCLASS()
class AURA_API UAttributeInfo : public UDataAsset
{
	GENERATED_BODY()
protected:
	virtual void PostLoad() override;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FAuraAttributeInfo> AttributeInformation;
	
public:
	FAuraAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound = false) const;
	
	FAuraAttributeInfo FindAttributeInfoForName(const FText& AttributeName, bool bLogNotFound=false) const;
};
