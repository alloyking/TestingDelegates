//
//  MTSlider.m
//  Delegates
//
//  Created by timshultis on 12/30/13.
//  Copyright (c) 2013 timshultis. All rights reserved.
//

#import "MTSlider.h"

@implementation MTSlider
@synthesize sliderDelegate;

- (id)initWithFrame:(CGRect)frame andDelegate:(id<MTSliderDelegate>)delegateObject{
    self = [super initWithFrame:frame];
    if (self) {
        self.sliderDelegate = delegateObject;
        self.value = [sliderDelegate startPositionForMTSlider:self];
    }
    return self;
}

- (void)setValue:(float)value animated:(BOOL)animated{
    [super setValue:value animated:animated];
    if (sliderDelegate != nil && [sliderDelegate respondsToSelector:@selector(MTSliderDidChange:withValue:)]){
        [[self sliderDelegate] MTSliderDidChange:self withValue:value];
    }
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
