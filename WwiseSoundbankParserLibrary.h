// ©2023 JDSherbert

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WwiseSoundbankParserLibrary.generated.h"

UCLASS()
class SHERBERT_API UWwiseSoundbankParserLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Sherbert|Wwise Soundbank Parser")
    static void GetEventIDAndName(const FString& SoundbankXmlPath, TMap<FString, FString>& EventMap);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Sherbert|Wwise Soundbank Parser")
    static void GetRTPCIDAndName(const FString& SoundbankXmlPath, TMap<FString, FString>& RTPCMap);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Sherbert|Wwise Soundbank Parser")
    static void GetSwitchIDAndName(const FString& SoundbankXmlPath, TMap<FString, FString>& SwitchMap);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Sherbert|Wwise Soundbank Parser")
    static void GetStateIDAndName(const FString& SoundbankXmlPath, TMap<FString, FString>& StateMap);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Sherbert|Wwise Soundbank Parser")
    static void GetAuxBusIDAndName(const FString& SoundbankXmlPath, TMap<FString, FString>& AuxBusMap);
};
