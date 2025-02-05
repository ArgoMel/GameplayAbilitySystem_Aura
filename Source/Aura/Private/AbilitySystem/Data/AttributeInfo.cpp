// Copyright Druid Mechanics


#include "AbilitySystem/Data/AttributeInfo.h"

#include "AuraGameplayTags.h"
#include "Aura/AuraLogChannels.h"

void UAttributeInfo::PostLoad()
{
	Super::PostLoad();
	AttributeInformation.Empty();
	const FAuraGameplayTags& gameplayTags = FAuraGameplayTags::Get();
	for (auto& attributeTag:gameplayTags.AttributeTags)
	{
		FAuraAttributeInfo auraAttributeInfo;
		auraAttributeInfo.AttributeTag=attributeTag.Key;
		TArray<FString> parseTags;
		attributeTag.Key.ToString().ParseIntoArray(parseTags,TEXT("."));
		auraAttributeInfo.AttributeName=FText::FromString(parseTags.Last());
		auraAttributeInfo.AttributeDescription=FText::FromString(attributeTag.Value);
		AttributeInformation.Add(auraAttributeInfo);
	}
}

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogAura, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(),*GetNameSafe(this));
	}

	return FAuraAttributeInfo();
}
