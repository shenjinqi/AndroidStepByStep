package personal.study.record.androidstepbystep;

import android.content.res.Resources;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.PopupWindow;


public class FragmentFind extends Fragment {

	private PopupWindow mPopupWindow;
	@Override
	public void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
	}

	@Override
	public View onCreateView(LayoutInflater inflater,
			@Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		View view = inflater.inflate(R.layout.find, null);

		View popup_view = inflater.inflate(R.layout.popup, null);
		mPopupWindow = new PopupWindow(popup_view, 300, 350);
		mPopupWindow.setFocusable(true);
		mPopupWindow.setOutsideTouchable(true);

		Button btCancel = ((Button) popup_view.findViewById(R.id.buttonCancel));
		btCancel.setOnClickListener(new Button.OnClickListener(){
			@Override
			public void onClick(View v) {
				System.out.printf("Cancel \n");
				mPopupWindow.dismiss();
			}
		});

		Button btCall = ((Button) popup_view.findViewById(R.id.buttonCall));
		btCall.setOnClickListener(new Button.OnClickListener(){
			@Override
			public void onClick(View v) {
				System.out.printf("Call \n");
				mPopupWindow.dismiss();
			}
		});

		Button btPopup=(Button)view.findViewById(R.id.buttonPopup);
		btPopup.setOnClickListener(new Button.OnClickListener(){
			@Override
			public void onClick(View v) {
				System.out.printf("Demo Popup windows \n");
				//popupWindow.dismiss();
				mPopupWindow.showAsDropDown(v);
			}
		});

		return view;
	}

}
