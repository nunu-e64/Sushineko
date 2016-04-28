<GameFile>
  <PropertyGroup Name="Character" Type="Node" ID="1c09fe7d-a94a-4a5c-8aa7-9b0a3f1514fb" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="5" Speed="0.5000" ActivedAnimationName="chop">
        <Timeline ActionTag="-681502177" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="2" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="3" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="4" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-681502177" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="1" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="2" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="3" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="4" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-681502177" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="2" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="3" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="4" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-681502177" Property="FileData">
          <TextureFrame FrameIndex="2" Tween="False">
            <TextureFile Type="Normal" Path="Assets/Images/resources-2x/character2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="Normal" Path="Assets/Images/resources-2x/character3.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="4" Tween="False">
            <TextureFile Type="Normal" Path="Assets/Images/resources-2x/character2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="Assets/Images/resources-2x/character1.png" Plist="" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="-681502177" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="2" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="3" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="4" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="5" Tween="False" Src="1" Dst="771" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="default" StartIndex="0" EndIndex="0">
          <RenderColor A="150" R="255" G="228" B="225" />
        </AnimationInfo>
        <AnimationInfo Name="chop" StartIndex="1" EndIndex="6">
          <RenderColor A="150" R="255" G="240" B="245" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Character" Tag="5" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Cat" ActionTag="-681502177" Tag="3" IconVisible="False" LeftMargin="-365.0000" TopMargin="-217.0000" ctype="SpriteObjectData">
            <Size X="365.0000" Y="217.0000" />
            <AnchorPoint ScaleX="1.0000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Assets/Images/resources-2x/character1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>