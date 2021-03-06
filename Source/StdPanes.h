#pragma once

class CommandPane
{
public:
	void ActivateReport(PaneReport *report);
	void AddUpdateRect(RECT *updateRect);
	int GetReportButtonHeight();
	ReportButton GetReportButton(ReportButtonType which);

	// todo: if other panes are added, this may be moved into a generic base class
	void AddButton(PaneButton *btn);
	void RemoveButton(PaneButton *btn);
};

extern void *cmdPane; // internal pointer

extern CommandPane gCommandPane;

// todo: other panes if useful?
