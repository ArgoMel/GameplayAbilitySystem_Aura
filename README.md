부모 유저위젯 설정할때 위젯 컨트롤러와 부모 오브젝트 설정하는게 좋을듯

AttributeMenu PreContstruct에서 어트리뷰트 개수만큼 자동 생성하게 변경(BFL에서 싱글톤 불러와서 반복문 돌리기)

몽타주 enum클래스 만들고 배열화 시키는게 좋을듯

디졸브 메터리얼은 메터리얼 함수로 변경(tps 참조)

ExecCalc_Damage에 auragameplaytag쪽 구조체를 같이 넣는게 난듯
AttributeSet에 변수명은 반드시 태그 끝네임이랑 동일하게 해야 노가다 안하게 할수있음

GA_ListenForEvent c++로 하면 배열 안만들어도 될듯

게임플레이 태그, 어빌리티, 모션 워핑(루트 모션 체크 필수) 플러그인 세팅
프로젝트 세팅 : 네비 클라이언트에서 실행 체크
모션블러 끄는게 나음
메쉬 디스턴스 필드 끄고 루멘 꺼야 그림자 자글거리는거 없어짐
ANIT-AILASING FXAA

DefaultGame : 
커스텀 FGameplayEffectContext 쓰는경우
[/Script/GameplayAbilities.AbilitySystemGlobals]
+AbilitySystemGlobalsClassName="/Script/Aura.AuraAbilitySystemGlobals"

클래스 생성시 저작권 표시
[/Script/EngineSettings.GeneralProjectSettings]
ProjectID=70BA0A3B40E2B9899612678C078FC24A
CopyrightNotice=Copyright Argo

커스텀 FGameplayEffectContext 설정,
게임플레이 큐 위치 설정(최적화 옵션)
[/Script/GameplayAbilities.AbilitySystemGlobals]
+AbilitySystemGlobalsClassName="/Script/Aura.AuraAbilitySystemGlobals"
+GameplayCueNotifyPaths=/Game/Blueprints/AbilitySystem/GameplayCueNotifies

DefaultEngine :
에셋매니저 클래스 설정
[/Script/Engine.Engine]
AssetManagerClassName=/Script/Aura.AuraAssetManager

게임플레이 큐 rpc 업데이트 빈도
[ConsoleVariables]
net.MaxRPCPerNetUpdate=10