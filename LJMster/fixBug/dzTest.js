
fixMethod('KDS_HomePageViewController','viewDidLoad',0,function(instance,invocation,arg){
  
          var co = new Array(Math.random(),Math.random(),Math.random(),Math.random());
          var color = runMethod('UIColor','colorWithRed:green:blue:alpha:',co);
          var view = runInstanceMethod(instance,'view');
          var label = runMethod('UILabel','new');
          runInstanceMethod(label,'setFrame:',new Array('{{100, 100}, {100, 100}}'));
          runInstanceMethod(label,'setText:','test');
          runInstanceMethod(view,'addSubview:',label);
          runInstanceMethod(label,'setBackgroundColor:',new Array(color));

          runInstanceMethod(view,'setBackgroundColor:',new Array(color));
 
          runLog("-----luojie-----") ;

          });

