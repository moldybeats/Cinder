#pragma once

#include "AudioTest.h"
#include "cinder/Tween.h"

#include "cinder/audio/Source.h"
#include "cinder/audio/Target.h"
#include "cinder/audio/dsp/Converter.h"
#include "cinder/audio/SamplePlayerNode.h"
#include "cinder/audio/SampleRecorderNode.h"
#include "cinder/audio/NodeEffects.h"
#include "cinder/audio/MonitorNode.h"

#include "../../../../samples/_audio/common/AudioDrawUtils.h"

class SamplePlayerTest : public AudioTest {
  public:
    SamplePlayerTest();

	void mouseDown( MouseEvent event ) override;

	//void keyDown( KeyEvent event ) override;
	void fileDrop( FileDropEvent event ) override;

	void update() override;
	void draw() override;
	void updateUI() override;

  private:
	void setupBufferPlayerNode();
	void setupFilePlayerNode();
	void setupBufferRecorderNode();
	void setSourceFile( const ci::DataSourceRef &dataSource );
	void writeRecordedToFile();
	void triggerStartStop( bool start );

	//void setupUI();
	//void processDrag( ivec2 pos );
	//void processTap( ivec2 pos );

	void seek( size_t xPos );
	void printBufferSamples( size_t xPos );
	void printSupportedExtensions();

	void testConverter();
	void testWrite();

	ci::audio::SamplePlayerNodeRef		mSamplePlayerNode;
	ci::audio::SourceFileRef			mSourceFile;
	ci::audio::MonitorNodeRef			mMonitor;
	ci::audio::GainNodeRef				mGain;
	ci::audio::Pan2dNodeRef				mPan;
	ci::audio::BufferRecorderNodeRef	mRecorder;

	WaveformPlot				mWaveformPlot;

	//vector<TestWidget *>		mWidgets;
	//Button						mEnableSamplePlayerNodeButton, mStartPlaybackButton, mStopPlaybackButton, mLoopButton, mAsyncButton, mRecordButton, mWriteButton, mAutoResizeButton;
	//VSelector					mTestSelector;
	//HSlider						mGainSlider, mPanSlider, mLoopBeginSlider, mLoopEndSlider, mTriggerDelaySlider;

	ci::Anim<float>					mUnderrunFade, mOverrunFade, mRecorderOverrunFade;
	ci::Rectf						mUnderrunRect, mOverrunRect, mRecorderOverrunRect;
	bool						mSamplePlayerNodeEnabledState;
	std::future<void>			mAsyncLoadFuture;
};
