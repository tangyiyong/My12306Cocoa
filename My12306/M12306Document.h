//
//  M12306Document.h
//  My12306
//
//  Created by 范 俊伟 on 13-7-11.
//  Copyright (c) 2013年 fjw. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "M12306GifView.h"
#import "M12306URLConnection.h"
#import "M12306TextField.h"
#import "M12306Form.h"
#import "M12306ComboBox.h"
#import "M12306passengerTicketItem.h"
#import "M12306PassengerTableView.h"
#import "M12306QueryTableView.h"
#import "M12306TrainInfo.h"
#import <WebKit/WebKit.h>
#import "M12306Utility.h"
#define COMMIT_DELAY_SECOND 5.0
#define HOST_URL @"https://kyfw.12306.cn"

typedef enum YUDING_STATUS_
{
    YUDING_STATUS_NONE,
    YUDING_STATUS_QUERY,
    YUDING_STATUS_YUDING,
    YUDING_STATUS_GET_IMG_CODE,
    YUDING_STATUS_WAIT_INPUT_IMG_CODE,
    YUDING_STATUS_CHECK_IMG_CODE,
    YUDING_STATUS_YUDING_CHECK,
    YUDING_STATUS_WAIT_ORDER,
    
}YUDING_STATUS;

typedef enum TASK_RESULT_
{
    TASK_RESULT_NONE,
    TASK_RESULT_YES,
    TASK_RESULT_ERROR,
    TASK_RESULT_ERROR_TO_QUERY,
}TASK_RESULT;

@interface M12306Document : NSDocument
//$$$$$$$$$$$$$$$$$$$$$$$$
@property (nonatomic) BOOL yudingLoopRun;
@property (nonatomic) BOOL yudingLoopRuning;
@property (nonatomic) YUDING_STATUS yudingStatus;
@property (nonatomic,strong) NSString * yudingResult;
@property (nonatomic) TASK_RESULT taskResult;
//$$$$$$$$$$$$$$$$$$$$$$$
@property (weak) IBOutlet NSTextField *txtTimeout;
- (IBAction)btnSetTimeoutClick:(id)sender;

@property (weak) IBOutlet NSProgressIndicator *queryProcess;
- (IBAction)getPassengerClick:(id)sender;

@property (weak) IBOutlet NSDatePicker *dpDingshi;

- (IBAction)dingshiClick:(id)sender;

- (IBAction)tablePassengerChange:(id)sender;
- (IBAction)btnStopYudingClick:(id)sender;
- (IBAction)btnYudingClick:(id)sender;
- (IBAction)loginOutClick:(id)sender;
@property (weak) IBOutlet M12306GifView *imgCommitCode;


@property (weak) IBOutlet M12306TextField *txtCommitCode;
@property (weak) IBOutlet NSTextField *lblDelayCommit;

@property (weak) IBOutlet NSTextField *txtTrainNameRegx;
@property (weak) IBOutlet M12306QueryTableView *dtQuery;
@property (weak) IBOutlet NSTableView *tableViewQuery;
@property (weak) IBOutlet NSDatePicker *dtpDate;
- (IBAction)btnSearchClick:(id)sender;
@property (weak) IBOutlet NSTextField *lblLoginMsg;
- (IBAction)popupSeat:(id)sender;
@property (weak) IBOutlet NSPopUpButton *popupSeat;
@property (weak) IBOutlet M12306PassengerTableView *tablePassenger;
@property (weak) IBOutlet NSScrollView *txtLogParent;
@property (weak) IBOutlet M12306GifView *imgLoginCode;


@property (weak) IBOutlet M12306ComboBox *cbxToStation;
@property (weak) IBOutlet M12306ComboBox *cbxFromStation;
@property (unsafe_unretained) IBOutlet NSTextView *txtLog;
@property (weak) IBOutlet NSTextField *txtUsername;
@property (weak) IBOutlet NSSecureTextField *txtPassword;
@property (weak) IBOutlet NSTextField *txtImgcode;

- (IBAction)btnLoginClick:(id)sender;
- (void)txtImgLoginCodeAction;
@property (strong)NSString* yudingSecretStr;
@property (strong,nonatomic) NSDictionary *seatData;
@property (strong,nonatomic) NSArray * stations;
@property BOOL isLogin;
@property (strong,nonatomic) NSArray* allPassengers;
@property NSInteger QueryCount;
@property NSArray* queryResultData;
@property (strong,nonatomic) M12306TrainInfo* currTrainInfo;
@property (strong,nonatomic) NSDate * getCommitTime;
@property (strong,nonatomic) NSString *lefttick;
@property (strong,nonatomic) NSString *token;
@property BOOL delayCommitRuning;
@property (strong,nonatomic)NSDictionary* savedDate;
@property (strong,nonatomic)NSString *loginKey;
@property (strong,nonatomic)NSString *loginValue;

@property (strong,nonatomic)NSString *queryKey;
@property (strong,nonatomic)NSString *queryValue;

//- (void) myinit;
//- (void) addLog:(NSString *) log;
//- (void) addLogLock:(NSString *)log;
//- (void) getLoginImgCode;
//- (NSImage *) getImageWithUrl:(NSString *)url refUrl:(NSString *)refUrl;
//- (void)delayLogin;
//- (void)login;
//- (void)loginLock;
//- (void)reLogin;
//- (NSData *)getData:(NSString *)url IsPost:(BOOL)isPost;
//- (NSString *)getText:(NSString *)url IsPost:(BOOL)isPost;
//- (id)getJson:(NSString *)url IsPost:(BOOL)isPost;
//- (void)initSeat;
//- (void)getStations;
//- (void)loginDidResult:(NSString *)result;
//- (void)getPassenger;
//- (NSString *)formatDate:(NSDate *) date strFormat:(NSString *)format;
//- (void)yudingDoResult:(NSString *)strResult;
////- (void)getCommitPage;
//- (void)getCommitImgCode;
//- (void)getCommitImgCodeLock;
//- (void)setCommitImgCodeLock:(NSImage *)image;
//-(void)txtCommitCodeTextChageAction;
//- (void)delayCommit;
//- (void)commitForLefttick:(NSString *)lefttick forToken:(NSString *)token forImgCode:(NSString *)imgCode;
//-(void)commitDoResult:(NSString *)strresult;
//- (void)checkForLefttick:(NSString *)lefttick forToken:(NSString *)token forImgCode:(NSString *)imgCode;
//- (BOOL)getTickCount;
//- (void)checkTickDoResult:(NSString *)strresult;
//-(void)getOrder;



@end
