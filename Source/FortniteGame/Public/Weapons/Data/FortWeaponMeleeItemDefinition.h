#pragma once

#include "CoreMinimal.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

#include "FortWeaponMeleeItemDefinition.generated.h"

class UParticleSystem;
class USoundBase;
class UAnimationAsset;
class UMaterialInterface;
class UMarshalledVFX_AuthoredDataConfig;
class UAnimInstance;


UCLASS()
class FORTNITEGAME_API UFortWeaponMeleeItemDefinition : public UFortWeaponItemDefinition
{
    GENERATED_BODY()

public:
    UFortWeaponMeleeItemDefinition();
    
    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UParticleSystem> IdleEffect;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UParticleSystem> SwingEffect;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UParticleSystem> AnimTrails;

    UPROPERTY(EditAnywhere)
    TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<USoundBase>> ImpactPhysicalSurfaceSoundsMap;

    UPROPERTY(EditAnywhere)
    TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<UParticleSystem>> ImpactPhysicalSurfaceEffectsMap;
    
    UPROPERTY(EditAnywhere)
    TArray<TSoftObjectPtr<UMaterialInterface>> WeaponMaterialOverrides;

    UPROPERTY(EditAnywhere)
    TSoftClassPtr<UAnimInstance> AnimClass;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UAnimationAsset> SingleAnimationToPlay;

    UPROPERTY(EditAnywhere)
    TMap<TEnumAsByte<EFortReloadFXState::Type>, TSoftObjectPtr<USoundBase>> ReloadSoundsMap;

    UPROPERTY(EditAnywhere)
    TMap<TEnumAsByte<EFortWeaponSoundState::Type>, TSoftObjectPtr<USoundBase>> PrimaryFireSoundMap;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<USoundBase> GenericImpactSound;
    
    UPROPERTY(EditAnywhere)
    FName AnimTrailsFirstSocketName;

    UPROPERTY(EditAnywhere)
    FName AnimTrailsSecondSocketName;

    UPROPERTY(EditAnywhere)
    float AnimTrailsWidth;

    UPROPERTY(EditAnywhere)
    bool bUseAnimTrails;

    UPROPERTY(EditAnywhere)
    bool bAttachAnimTrailsToWeapon;

    UPROPERTY(EditAnywhere)
    FName IdleFXSocketName;

    UPROPERTY(EditAnywhere)
    FName SwingFXSocketName;

    UPROPERTY(EditAnywhere)
    bool bNeedsMaterial0MID;

    UPROPERTY(EditAnywhere)
    bool bWatchKills;

    UPROPERTY(EditAnywhere)
    bool bCandyCaneKillReaction;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        return FPrimaryAssetId("Weapon", GetFName());
    }
};