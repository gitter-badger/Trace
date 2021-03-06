//
// rayUI.h
//
// The header file for the UI part
//

#ifndef __rayUI_h__
#define __rayUI_h__

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Button.H>

#include <FL/fl_file_chooser.H>		// FLTK file chooser

#include "TraceGLWindow.h"

class TraceUI {
public:
	TraceUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;

	Fl_Slider*			m_sizeSlider;
	Fl_Slider*			m_depthSlider;
	Fl_Slider*			m_threadSlider;
	// caustic
	Fl_Light_Button*	m_traceButton;
	Fl_Light_Button*	m_causticButton;
	Fl_Slider*			m_photonNumSlider;
	Fl_Slider*			m_queryNumSlider;
	Fl_Slider*			m_coneFilterSlider;
	Fl_Slider*			m_causticAmplifySlider;

	Fl_Button*			m_renderButton;
	Fl_Button*			m_stopButton;
	Fl_Light_Button*	m_softShadowButton;
	Fl_Light_Button*	m_fresnelSwitch;
	TraceGLWindow*		m_traceGlWindow;
	Fl_Button*		m_threadButton;

	bool IsEnableSoftShadow() const
	{
		return m_is_enable_soft_shadow;
	}
	bool IsEnableFresnel() const
	{
		return m_is_enable_fresnel;
	}
	// member functions
	void show();

	void		setRayTracer(RayTracer *tracer);

	int			getSize();
	int			getDepth();
	int	getThread() const
	{
		return m_thread;
	}

private:
	RayTracer*	raytracer;

	int			m_nSize;
	int			m_nDepth;
	int			m_thread;
	//caustic
	int			m_nPhotonNumOrder;
	int			m_nQueryNum;
	bool		m_bTrace;
	bool		m_bCaustic;
	double		m_dConeAtten;
	double		m_dCausticAmplify;
	bool		m_is_enable_soft_shadow;
	bool		m_is_enable_fresnel;
// static class members
	static Fl_Menu_Item menuitems[];

	static TraceUI* whoami(Fl_Menu_* o);

	static void cb_load_scene(Fl_Menu_* o, void* v);
	static void cb_save_image(Fl_Menu_* o, void* v);
	static void cb_load_height_map(Fl_Menu_* o, void* v);
	static void cb_load_background_image(Fl_Menu_* o, void* v);
	static void cb_clear_background_image(Fl_Menu_* o, void* v);
	static void cb_exit(Fl_Menu_* o, void* v);
	static void cb_about(Fl_Menu_* o, void* v);
	static void cb_fresnelSwitch(Fl_Widget* o, void* v);
	static void cb_exit2(Fl_Widget* o, void* v);

	static void cb_sizeSlides(Fl_Widget* o, void* v);
	static void cb_depthSlides(Fl_Widget* o, void* v);
	//caustic
	static void cb_traceToggle(Fl_Widget* o, void* v);
	static void cb_causticToggle(Fl_Widget* o, void* v);
	static void cb_photonNumberSlides(Fl_Widget* o, void* v);
	static void cb_queryNumSlides(Fl_Widget* o, void* v);
	static void cb_coneFilterSlides(Fl_Widget* o, void* v);
	static void cb_causticAmplifySlides(Fl_Widget* o, void* v);
	static void cb_softShadowButton(Fl_Widget* o, void* v);
	static void cb_threadSlides(Fl_Widget* o, void* v);
	static void cb_threadrender(Fl_Widget* o, void* v);

	static void cb_render(Fl_Widget* o, void* v);
	static void cb_stop(Fl_Widget* o, void* v);

	static void RenderWorker(TraceUI *ui, const int from_y, const int to_y, const int w);
};

#endif
