#pragma once

#include<vector>

#include<collection.h>

#include"LeapSDK\include\Leap.h"

#include"LeapBridge\Interface.h"
#include"LeapBridge\Utilities.h"
#include"LeapBridge\Vector.h"
#include"LeapBridge\InteractionBox.h"
#include"LeapBridge\Pointable.h"
#include"LeapBridge\Frame.h"
#include"LeapBridge\Hand.h"

#pragma comment(lib, "LeapSDK/lib/x86/leap.lib")

namespace LeapBridge
{
	public delegate void LeapEventHandler(Controller^ controller);

	class ListenerBridge : public Leap::Listener
	{
	private:
		LeapBridge::Controller^ listener_;

	public:
		ListenerBridge(LeapBridge::Controller^ listener)
		{
			listener_ = listener;
		}

		virtual void onInit(const Leap::Controller&);
		virtual void onConnect(const Leap::Controller&);
		virtual void onDisconnect(const Leap::Controller&);
		virtual void onExit(const Leap::Controller&);
		virtual void onFrame(const Leap::Controller&);
		virtual void onFocusGained(const Leap::Controller&);
		virtual void onFocusLost(const Leap::Controller&);
	};

	// Implementation
	public ref class Controller sealed
	{
	private:
		friend class ListenerBridge;

		Leap::Controller controller_;
		ListenerBridge* bridge_;

#pragma region Event Trigger
		void OnInit(){ Init(this); }
		void OnConnect(){ Connect(this); }
		void OnDisconnect(){ Disconnect(this); }
		void OnExit(){ Exit(this); }
		void OnFrame(){ Frame(this); }
		void OnFocusGained(){ FocusGained(this); }
		void OnFocusLost(){ FocusLost(this); }
#pragma endregion

	public:
		Controller();
		virtual ~Controller();

		property bool IsConnected {
			bool get() { return controller_.isConnected(); }
		}
		property bool HasFocus {
			bool get() { return controller_.hasFocus(); }
		}
		property PolicyFlag PolicyFlags{
			PolicyFlag get(){
				return (PolicyFlag) (controller_.policyFlags());
			}
			void set(PolicyFlag flags){
				controller_.setPolicyFlags((Leap::Controller::PolicyFlag)flags);
			}
		}
		property Config^ Config
		{
			LeapBridge::Config^ get(){
				return nullptr;
			}
		}
		property Windows::Foundation::Collections::IVectorView<Device^>^ Devices
		{
			Windows::Foundation::Collections::IVectorView<Device^>^ get()
			{
				return nullptr;
			}
		}
		property Windows::Foundation::Collections::IVectorView<Screen^>^ LocatedScreens
		{
			Windows::Foundation::Collections::IVectorView<Screen^> ^get()
			{
				return nullptr;
			}
		}
		property Windows::Foundation::Collections::IVectorView<Screen^>^ CaplibratedScreens
		{
			Windows::Foundation::Collections::IVectorView<Screen^> ^get()
			{
				return nullptr;
			}
		}

		void EnableGesture(GestureType type){
			controller_.enableGesture((Leap::Gesture::Type)type, true);
		}
		void DisableGesture(GestureType type){
			controller_.enableGesture((Leap::Gesture::Type)type, false);
		}
		bool IsGestureEnabled(GestureType type) {
			return controller_.isGestureEnabled((Leap::Gesture::Type)type);
		}

		Frame^ GetFrame(int history);
		Frame^ GetFrame(){ return GetFrame(0); }

		event LeapEventHandler^ Init;
		event LeapEventHandler^ Connect;
		event LeapEventHandler^ Disconnect;
		event LeapEventHandler^ Exit;
		event LeapEventHandler^ Frame;
		event LeapEventHandler^ FocusGained;
		event LeapEventHandler^ FocusLost;
	};

	public ref class Config sealed
	{

	};

	public ref class Screen sealed
	{

	};

	public ref class Device sealed
	{

	};

	/////////
	public ref class Gesture sealed
	{
		friend Gesture^ LeapTypeToBridge<Gesture>(Leap::Gesture&);
	};
}