//
//  MTSlider.h
//  Delegates
//
//  Created by timshultis on 12/30/13.
//  Copyright (c) 2013 timshultis. All rights reserved.
//

#import <UIKit/UIKit.h>

//By placing @class above everything else, the compiler is informed that at some point down the line, MTSlider will be
//declared. Without this compiler directive, the compiler will give you a warning because it is expecting to find the
//interface for MTSlider right away.
@class MTSlider;

//Declaring the Delegate Methods

//using nsobject as it contains a method, respondsToSelector:, that can be used to
//ensure the delegate object actually implements an optional method before the method is called.
@protocol MTSliderDelegate <NSObject>

//an optional method is a method that does not have to be implemented by the delegate object; in this case the delegate
//object will be the ViewController, however it could be any object. The optional method MTSliderDidChange:withValue: is
//messaged in the delegate object when the slider's value changes.
@optional
- (void)MTSliderDidChange:(MTSlider *)MTSlider withValue:(CGFloat)value;

//a required method is a method that must be implemented by the delegate object or else you will get a compiler warning. The
//required method startPositionForMTSlider: asks the delegate object where the sliders should start and gets its starting
//position value in return from the delegate.
@required
- (CGFloat)startPositionForMTSlider:(MTSlider *)MTSlider;


@end


@interface MTSlider : UISlider {

    //use __weak when using arc?
    //The ivar is of type id so it is flexible and can accept any object type. The next part, MTSliderDelegate says that
    //whatever object ends up being assigned to sliderDelegate will contain the protocol methods of MTSliderDelegate as part
    //of its own implementation.
    __weak id <MTSliderDelegate> sliderDelegate;

}
//again note the use of weak for arc.
@property (nonatomic, weak) id <MTSliderDelegate> sliderDelegate;

- (id)initWithFrame:(CGRect)frame andDelegate:(id<MTSliderDelegate>)delegateObject;

@end
