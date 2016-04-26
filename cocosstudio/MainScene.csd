<GameFile>
  <PropertyGroup Name="MainScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="640.0000" Y="960.0000" />
        <Children>
          <AbstractNodeData Name="background_1" ActionTag="2039903722" Tag="8" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-64.0000" RightMargin="-64.0000" TopMargin="-176.0000" ctype="SpriteObjectData">
            <Size X="768.0000" Y="1136.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" />
            <PreSize X="1.2000" Y="1.1833" />
            <FileData Type="Normal" Path="Assets/Images/resources-2x/background.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="character" ActionTag="690027771" Tag="9" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="320.0000" RightMargin="320.0000" TopMargin="730.0000" BottomMargin="230.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="320.0000" Y="230.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.2396" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Character.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="mainPieceNode" ActionTag="-81594889" Tag="12" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="320.0000" RightMargin="320.0000" TopMargin="668.0000" BottomMargin="292.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="1.0000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="320.0000" Y="292.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.3042" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Piece.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="pieceNode" ActionTag="-2114846933" Tag="17" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="320.0000" RightMargin="320.0000" TopMargin="554.0000" BottomMargin="406.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="320.0000" Y="406.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4229" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="scoreLabel" ActionTag="-1976996823" Tag="18" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="293.5000" RightMargin="293.5000" TopMargin="278.5000" BottomMargin="566.5000" FontSize="100" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="53.0000" Y="115.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="624.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.6500" />
            <PreSize X="0.0828" Y="0.1198" />
            <FontResource Type="Normal" Path="Assets/Fonts/Game of Three.ttf" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="play" ActionTag="-1685017609" VisibleForFrame="False" Tag="19" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="218.5000" RightMargin="218.5000" TopMargin="417.0000" BottomMargin="417.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="173" Scale9Height="104" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="203.0000" Y="126.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="480.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.3172" Y="0.1312" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="Assets/Images/resources-2x/buttonPressed.png" Plist="" />
            <NormalFileData Type="Normal" Path="Assets/Images/resources-2x/button.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="lifeBG" ActionTag="-158197328" Tag="20" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="166.5000" RightMargin="166.5000" TopMargin="19.2000" BottomMargin="858.8000" ctype="SpriteObjectData">
            <Size X="307.0000" Y="82.0000" />
            <Children>
              <AbstractNodeData Name="lifeBar" ActionTag="-1861469373" Tag="21" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="16.5000" BottomMargin="16.5000" ctype="SpriteObjectData">
                <Size X="272.0000" Y="49.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="17.0000" Y="41.0000" />
                <Scale ScaleX="0.5000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0554" Y="0.5000" />
                <PreSize X="0.8860" Y="0.5976" />
                <FileData Type="Normal" Path="Assets/Images/resources-2x/life.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="320.0000" Y="940.8000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.9800" />
            <PreSize X="0.4797" Y="0.0854" />
            <FileData Type="Normal" Path="Assets/Images/resources-2x/life_bg.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>