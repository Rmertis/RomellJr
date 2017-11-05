#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <cstdlib>
#include <Joystick.h>
#include <CANTalon.h>
#include <time.h>
//================================================================================
//                         Romell Junior                                        //
//================================================================================

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {

		//=== JoySticks ===

		Lstick = new Joystick(0);
		Rstick = new Joystick(1);

		//=== Motors ===

		fL = new CANTalon(15);
		fR = new CANTalon(0);
		bL = new CANTalon(14);
		bR = new CANTalon(1);


	}


	void AutonomousInit() override {

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {

		//========================================== Joysticks ==============================================

		//=== Right Stick ===

		if(Rstick->GetRawAxis(1 < 2.4 && Rstick->GetRawAxis(1) > -2.4))
		{
			fR->Set (-Rstick->GetRawAxis(1));
			bR->Set (-Rstick->GetRawAxis(1));
		}

		//=== Left Stick ===

		if(Lstick->GetRawAxis(1 < 2.4 && Lstick->GetRawAxis(1) > -2.4))
				{
					fL->Set (-Lstick->GetRawAxis(1));
					bL->Set (-Lstick->GetRawAxis(1));
				}
		//=====================================================================================================
	}


	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();

	//=== JoyStick ===

	Joystick *Rstick;
	Joystick *Lstick;

	//=== 4motors ===
		CanTalonSRX *fL;
		CanTalonSRX *fR;
		CanTalonSRX *bL;
		CanTalonSRX *bR;

};

START_ROBOT_CLASS(Robot)
